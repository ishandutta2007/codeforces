#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m, p;
const int maxN = 2e5 + 10;
ll mask[maxN];
int bit[60];
int cnt[(1 << 20) + 5];
int bits[(1 << 20) + 5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    for (int i = 1; i < (1 << 20); i++) bits[i] = bits[i >> 1] + (i & 1);
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ll t = 0;
        reverse(s.begin(), s.end());
        for (char& c : s) {
            t = (2 * t + (c - '0'));
        }
        mask[i] = t;
    }
    mt19937 rnd(228);
    int best = 0;
    ll ans = 0;
    for (int iter = 0; iter < 150; iter++) {
        int who = rnd() % n;
        int SZ = 0;
        for (int j = 0; j < m; j++) {
            if (mask[who] & (1LL << j)) {
                bit[SZ++] = j;
            }
        }
        memset(cnt, 0, sizeof cnt);
        for (int x = 0; x < n; x++) {
            int cur = 0;
            for (int c = 0; c < SZ; c++) {
                if (mask[x] & (1LL << bit[c])) {
                    cur |= (1 << c);
                }
            }
            cnt[cur]++;
        }
        for (int r = 0; r < SZ; r++) {
            for (int x = 0; x < (1 << SZ); x++) {
                if (x & (1 << r)) {
                    cnt[x ^ (1 << r)] += cnt[x];
                }
            }
        }
        for (int z = 0; z < (1 << SZ); z++) {
            if (cnt[z] >= (n + 1) / 2 && bits[z] > best) {
                best = bits[z];
                ll cur = 0;
                for (int p = 0; p < SZ; p++) {
                    if (z & (1 << p)) cur |= (1LL << bit[p]);
                }
                ans = cur;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (ans & (1LL << i)) cout << 1;
        else cout << 0;
    }
    return 0;
}