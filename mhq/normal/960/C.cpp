#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, d;
vector < ll > ans;
ll prv = 1;
void solve(ll x) {
    //cout << x << endl;
    if (x == 0) return ;
    for (int i = 60; i >= 0; i--) {
        if ((1LL << i) - 1 <= x) {
            //cout << i << endl;
            x -= ((1LL << i) - 1);
            for (int j = 1; j <= i; j++) ans.push_back(i + prv);
            prv += 5 * (ll)1e9;
            solve(x);
            return ;
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> x >> d;
    solve(x);
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}