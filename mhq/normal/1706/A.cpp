#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
const int maxN = 1e5 + 10;
int dp[maxN];
int c[maxN];
int best[maxN];
vector<int> vals[maxN];
void solve() {
    int n, m;
    cin >> n >> m;
    string s(m, 'B');
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        x--;
        x = min(x, m - 1 - x);
        if (s[x] == 'B') {
            s[x] = 'A';
        }
        else {
            s[m - 1 - x] = 'A';
        }
    }
    cout << s << '\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}