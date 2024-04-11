#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int tst;
const int maxN = 2e5 + 10;
int a[maxN];
int pos[maxN];
int f[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        f[(i + n - pos[x]) % n]++;
    }
    int mn = 0;
    for (int i = 0; i < n; i++) mn = max(mn, f[i]);
    cout << mn;
    return 0;
}