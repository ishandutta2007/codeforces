#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
int n;
vector < int > f[maxN];
int t[maxN * 10];
int s[maxN * 10];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    ll tot = (1LL * n * n);
    vector < int > good;
    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;
        f[i].resize(len);
        for (int& v : f[i]) cin >> v;
        bool ok = true;
        for (int j = 0; j + 1 < len; j++) {
            if (f[i][j] < f[i][j + 1]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            t[f[i].back()]++;
            s[f[i][0]]++;
        }
    }
    ll pref = 0;
    for (int i = 0; i <= 1000000; i++) {
        pref += s[i];
        tot -= pref * t[i];
    }
    cout << tot;
    return 0;
}