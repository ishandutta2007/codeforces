#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
 
const int inf = 1e9;
const ll inf64 = 1e18;
 
const int N = 1e6 + 5;
 
int n, k;
int phi[N];
int pr[N], perm[N];
 
int main() {
 
#ifdef debug
    freopen("input.txt", "r", stdin);
#endif
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> k;
 if (k == 1) {
     cout << 3;
     return 0;
 }
    fill(pr, pr + N, 1);
    pr[0] = pr[1] = 0;
    for (int p = 2; p * p < N; p++) {
        if (!pr[p]) continue;
        for (int i = p * p; i < N; i += p) {
            pr[i] = 0;
        }
    }
    fill(phi, phi + N, 1);
    for (int p = 2; p < N; p++) {
        if (!pr[p]) continue;
        for (int i = p; i < N; i += p) {
            int x = i / p, y = 1;
            while (x % p == 0) {
                x /= p;
                y *= p;
            }
            phi[i] *= y * (p - 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        perm[i] = i;
    }
    sort(perm + 1, perm + n + 1, [&](int i, int j) {
        return phi[i] < phi[j] || (phi[i] == phi[j] && i < j);
    });
    ll res = 0;
    for (int i = 1; i <= k + 2; i++) {
//        cout << perm[i] << " " << phi[perm[i]] << "\n";
        res += phi[perm[i]];
    }
//    cout << "\n";
    cout << res << "\n";
 
    return 0;
}