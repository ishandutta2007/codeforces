#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

struct truck {
    int s, f, c, r;

    truck () {}
    truck (int s, int f, int c, int r) : s(s), f(f), c(c), r(r) {}

    void read () {
        scanf("%d %d %d %d", &s, &f, &c, &r);
    }
}x[nax];

mt19937 rng((unsigned long long)(new char()));

const long long lim = 1e18;
int n, m;
int a[nax];
int ind[nax];
long long cur_max;

int get_par (truck &b, long long V) {

    auto [s, f, c, r] = b;

    long long cur_sum = 0;
    int cnt = 0;
    for (int i = s + 1 ; i <= f ; ++ i) {
        cur_sum += (a[i] - a[i - 1]);
        if (cur_sum * c > V) {
            ++ cnt;
            cur_sum = a[i] - a[i - 1];
        }
        if (cur_sum * c > V) return INT_MAX;
    }
    return cnt;
}

void get_par (truck &b) {
    if (get_par(b, cur_max) <= b.r) return ;

    long long l = cur_max, r = lim, ans = -1;
    while (l <= r) {
        long long mid = l + r >> 1;
        if (get_par(b, mid) <= b.r) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cur_max = ans;
    return ;
}

int main () {

    scanf("%d %d", &n, &m);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
    }

    for (int i = 1 ; i <= m ; ++ i) {
        x[i].read();
    }
    iota(ind + 1, ind + 1 + m, 1);
    shuffle(ind + 1, ind + 1 + m, rng);

    for (int _ = 1 ; _ <= m ; ++ _) {
        int i = ind[_];
        get_par(x[i]);
    }

    printf("%lld\n", cur_max);
}