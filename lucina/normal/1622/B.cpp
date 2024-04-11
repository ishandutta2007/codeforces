#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int p[nax];
int ans[nax];
char s[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> p[i];
    cin >> s + 1;
    vector <pair < int, int>> v1, v2;
    for (int i = 1 ; i <= n ; ++ i) {
        if (s[i] == '1') {
            v1.emplace_back(p[i], i);
        } else v2.emplace_back(p[i], i);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int cur = 1;
    for (auto &[_, x] : v2) {
        ans[x] = cur++;
    }
    for (auto &[_, x] : v1) {
        ans[x] = cur++;
    }
    for (int i = 1 ; i <= n ; ++ i)
        cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ; ) {
        solve();
    }

}