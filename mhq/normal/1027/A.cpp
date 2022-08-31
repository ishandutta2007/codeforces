#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rank pankshpank
int tst;
int n;
string s;
void solve() {
    cin >> n >> s;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        int y = s[n - 1 - i] - 'a';
        if (x == y || abs(x - y) == 2) continue;
        ok = false;
    }
    if (ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> tst;
    while (tst--) solve();
    return 0;
}