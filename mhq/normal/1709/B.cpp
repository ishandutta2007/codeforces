#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 1e5 + 10;
ll a[maxN];
ll pA[maxN];
ll pB[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        pA[i] = pA[i - 1];
        if (a[i] > a[i + 1]) pA[i] += a[i] - a[i + 1];
    }
    for (int i = 2; i <= n; i++) {
        pB[i] = pB[i - 1];
        if (a[i] > a[i - 1]) pB[i] += a[i] - a[i - 1];
    }
    while (m--) {
        int s, t;
        cin >> s >> t;
        if (s < t) {
            cout << pA[t - 1] - pA[s - 1] << '\n';
        }
        else {
            cout << pB[s] - pB[t] << '\n';
        }
    }
    return 0;
}