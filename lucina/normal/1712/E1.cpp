#include<bits/stdc++.h>
using namespace std;
const int nax = 4e5 + 10;

int64_t c3(int64_t x) {
    return x * (x - 1) * (x - 2) / 6;    
}
int64_t c2(int64_t x) {
    if (x < 0) return 0;
    return x * (x - 1) / 2;
}


int l, r;
int q;
array <int, 3> queries[nax];
int64_t ans[nax];
int cnt[nax];
struct Fenwick {
    int64_t bit[nax];
    Fenwick() {memset(bit, 0, sizeof(bit));}

    void update(int idx, int64_t val) {
        for (;idx < nax ; idx += idx & -idx) bit[idx] += val;
    }
    int64_t get(int idx) {
        int64_t res = 0;
        for (; idx > 0 ; idx -= idx & -idx) res += bit[idx];
        return res;
    }
    int64_t get(int l, int r) {
        return get(r) - get(l - 1);
    }
};
inline bool valid(int l, int r) {
    return r % 3 == 0 && l > r / 3 && l < 2 * r / 3;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    cin >> q;
    for (int i = 1 ; i <= q ; ++ i) {
        cin >> queries[i][0] >> queries[i][1];
        queries[i][2] = i;
    }
    
    sort(queries + 1, queries + 1 + q);
    reverse(queries + 1, queries + 1 + q);
    int ptr_r = 2e5;
    
    Fenwick cnt_k;
    
    for (int i = 1 ; i <= q ; ++ i) {
        auto [l, r, id] = queries[i];
        while (ptr_r >= l) {
            int j = ptr_r;
            for (int x = j ; x < nax ; x += j) {
                cnt_k.update(x, -c2(cnt[x] - 1));
                cnt[x] += 1;
                if (valid(j, x)) cnt_k.update(x, 1);
                if (x % 2 == 0 && (x / 2) % j && valid(j, x / 2)) cnt_k.update(x / 2, 1);
                cnt_k.update(x, c2(cnt[x] - 1));
            }
            ptr_r -= 1;
        }
        ans[id] = c3(r - l + 1) - cnt_k.get(l, r);
    }
    for (int i = 1 ; i <= q ; ++ i) cout << ans[i] << '\n';
    
}