#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
const int MOD = 998244353;
int n;
string s;
int cnt = 0;
string dfs(int v) {
    if (v * 2 + 1 >= s.size()) {
        return to_string(s[v]);
    }
    string l = dfs(v * 2 + 1), r = dfs(v * 2 + 2);
    if (l != r) cnt += 1;
    if (l > r) swap(l, r);
    return l + s[v] + r;

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> s;
    dfs(0);
    int ans = 1;
    for (int i = 1 ; i <= cnt ; ++ i)
        ans = ans * 2 % MOD;
    cout << ans << '\n';
}