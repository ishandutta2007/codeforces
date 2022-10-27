#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n;
vector <int> seg;
int64_t m;
 
inline int64_t sq(int64_t x) {
    return x * x;
}
 
inline int64_t cut_cost(int l, int k) {
    int d = l / k; /// cutting to k sub segments
    int res = l - d * k;
    return sq(d) * (k - res) + sq(d + 1) * (res);
}
 
inline int64_t improve(int l, int k) {
    return (l > 1) * (cut_cost(l, k) - cut_cost(l, k + 1));
}
 
int when(int l, int64_t better) {
    int x = 1, y = l - 1, ans = 1;
    while (x <= y) {
        int mid = x + y >> 1;
        if (improve(l, mid) > better) {
            ans = mid;
            x = mid + 1;
        } else y = mid - 1;
    }
    return ans;
}
 
int how_long(int l, int k) {
    int x = k, y = l, ans = -1;
    int64_t base = improve(l, k);
    while (x <= y) {
        int mid = x + y >> 1;
        if (improve(l, mid) == base) {
            ans = mid;
            x = mid + 1;
        } else y = mid - 1;
    }
    return ans;
}
 
pair <bool, int> ok(int64_t lst) {
    int cnt = 0;
    int64_t tot = 0, can = 0;
    for (int i = 0 ; i < n ; ++ i) {
        int k = when(seg[i], lst);
        if (improve(seg[i], k) > lst)
            k += 1;
        tot += cut_cost(seg[i], k);
        cnt += k - 1;
        if (improve(seg[i], k) == lst)
            can += how_long(seg[i], k) - k + 1;
    }
    int64_t need = tot - m;
    if (need <= 0) return make_pair(true, cnt);
    int64_t foo = min(can, (need + lst - 1) / lst);
    need -= lst * foo;
    cnt += foo;
    return make_pair(need <= 0, cnt);
}
 
int main() {
    scanf("%d", &n);
    seg.resize(n);
    for (int i = 0, x = 0, y ; i < n ; ++ i) {
        scanf("%d", &y);
        seg[i] = (y - x);
        x = y;
    }
    sort(seg.begin(), seg.end());
 
    scanf("%lld", &m);
    int ans;
    int64_t l = 0, r = improve(seg.back(), 1);
    while (l <= r) {
        int64_t mid = l + r >> 1;
        auto [good, cnt] = ok(mid);
        if (good) {
            l = mid + 1;
            ans = cnt;
        } else r = mid - 1;
    }
 
    printf("%lld\n", ans);
}
 
    /**
        4 -> 1 1 1 1 | + 4
        -> 1 1 2
        +4 + 1 + 1
 
        we first start with largest segment
        we need at least 2 ->
        on largest segment divide it to certain size
 
        First divide it such that it is no longer maximum
 
        7
        3 4 = 9 + 16 = 25
        2 2 3 = 4 + 4 + 9 = 17
        1 2 2 2 = 1 + 4 + 4 + 4 = 13
        1 1 1 2 2 = 1 + 1 + 1 + 4 + 4 = 11
        1 1 1 1 1 2 = 1 + 1 + 1 + 1 + 1 +4 = 9
        1 1 1 1 1 1 1 = 7
        sound so convex?
        5 -> 2, 3 = 25 - 4 - 9 = 12
        100 = 5 ,20,
        estimate differences would be
        x * (C / x) ^ 2 - (x + 1) * (C /(x + 1)) ^ 2
        around C^2/x - c^2/(x + 1)
        (C^2)1/x - 1 / (x + 1)
 
        But you can actually soil down the number as that place,
        how many that actually HIT?
        (x x x x) x+1 x+1 x+1
        if it's the same we can actually easy to calculate it?
 
        In stead, what if we binary search on Minimum differences?....
        Look working?
    */