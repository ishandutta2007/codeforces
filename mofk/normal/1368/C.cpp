#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector <pair <int, int> > ans;
    for (int i = 0; i < n + 2; ++i) ans.push_back({i, i});
    for (int i = 0; i < n + 1; ++i) ans.push_back({i + 1, i});
    for (int i = 0; i < n + 1; ++i) ans.push_back({i, i + 1});
    cout << ans.size() << endl;
    for (auto x: ans) cout << x.first << ' ' << x.second << endl;
    return 0;
}