#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 105;
int a[maxN];
int bits[(1 << 15) + 10];
map < vector < int >, int > mp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    bits[0] = 0;
    for (int i = 1; i < (1 << 15); i++) bits[i] = bits[i / 2] + (i & 1);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int mask = 0; mask < (1 << 15); mask++) {
        vector < int > p1(n), p2(n);
        for (int p = 0; p < n; p++) {
            int val1 = a[p] & ((1 << 15) - 1);
            p1[p] = bits[val1 ^ mask];
        }
        int val = p1[0];
        for (int& u : p1) u -= val;
        mp[p1] = mask;
    }
    for (int mask = 0; mask < (1 << 15); mask++) {
        vector < int > p2(n);
        for (int p = 0; p < n; p++) {
            int val1 = a[p] >> 15;
            p2[p] = bits[val1 ^ mask];
        }
        int val = p2[0];
        for (int& u : p2) {
            u -= val;
            u = -u;
        }
        if (mp.count(p2)) {
            int x = mp[p2] + (1 << 15) * mask;
            vector < int > shit;
            for (int p = 0; p < n; p++) {
                int c = a[p] ^ x;
                shit.emplace_back(bits[c >> 15] + bits[c & ((1 << 15) - 1)]);
            }
            for (int u : shit) assert(u == shit[0]);
            cout << x << '\n';
            return 0;
        }
    }
    cout << -1;
    return 0;
}