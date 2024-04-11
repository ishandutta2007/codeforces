#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;
const int maxN = 2 * (int)1e5 + 10;
bool used[maxN];
vector < int > ans[2];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> a >> b;
    ll s = a + b;
    int optk = -1;
    for (int i = 1; ; i++) {
        if (1LL * i * (i + 1) > 2 * s) {
            optk = i - 1;
            break;
        }
    }
    a = 1LL * optk * (optk + 1) / 2 - b;
    ll cur = optk;;
    while (cur > 0) {
        if (a >= cur) {
            a -= cur;
            ans[0].push_back(cur);
        }
        else {
            ans[1].push_back(cur);
        }
        cur--;
    }
    cout << ans[0].size() << '\n';
    for (int v : ans[0]) cout << v << " ";
    cout << '\n';
    cout << ans[1].size() << '\n';
    for (int v : ans[1]) cout << v << " ";
}