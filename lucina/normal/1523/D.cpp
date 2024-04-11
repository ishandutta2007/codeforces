#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
int perm[nax];
int n, m, _p;
int64_t a[nax];
char s[nax];
int cnt[nax];
int64_t ans = 0;
void test(int idx) {
    int64_t s = a[idx];
    vector <int64_t> x;
    while (s > 0) {
        x.push_back(s & -s);
        s -= s & -s;
    }
    int p = x.size();
    fill(cnt, cnt + (1 << p), 0);
    for (int i = 1 ; i <= n ; ++ i) {
        int b = 0;
        for (int j = 0 ; j < p ; ++ j) {
            if (a[i] & x[j])
                b ^= 1 << j;
        }
        cnt[b] += 1;
    }

    for (int i = 0 ; i < p ; ++ i)
    for (int msk = 0 ; msk < (1 << p) ; ++ msk) {
        if (msk >> i & 1) cnt[msk ^ (1 << i)] += cnt[msk];
    }
    /**
    */
    int mx_cnt = 0, msk = -1;
    for (int i = 0 ; i < (1 << p) ; ++ i) {
        if (cnt[i] >= (n + 1) / 2 && __builtin_popcount(i) > mx_cnt) {
            msk = i;
            mx_cnt = __builtin_popcount(i);
        }
    }
    if (msk != -1 && __builtin_popcount(msk) > __builtin_popcountll(ans)) {
        ans = 0;
        for (int j = 0 ; j < p ; ++ j)
            if (msk >> j & 1) ans ^= x[j];
    }
}
/**
    1110010101
    1110010101
    1110010101
*/

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m >> _p;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> s;
        for (int j = 0 ; j < m ; ++ j) {
            a[i] = a[i] * 2 + s[j] - '0';
        }
    }
    iota(perm + 1, perm + 1 + n, 1);
    shuffle(perm + 1, perm + 1 + n, rng);
    double st = clock();
    int c = 1;
    while (c <= min(n, 7)) {
        test(perm[c++]);
    }//
    for (int j = m - 1; j >= 0 ; -- j) {
        cout << (ans >> j & 1);
    }
    cout << '\n';

}