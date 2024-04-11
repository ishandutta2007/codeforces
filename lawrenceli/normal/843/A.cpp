#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;

int n;
int a[maxn], pos[maxn];
pair<int, int> sorted[maxn];
vector<vector<int> > ans;
bool vis[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sorted[i] = make_pair(a[i], i);
    }
    sort(sorted + 1, sorted + n + 1);

    for (int i = 1; i <= n; i++) pos[sorted[i].second] = i;

    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            ans.push_back(vector<int>());
            int cur = i;
            while (!vis[cur]) {
                vis[cur] = 1;
                ans.back().push_back(cur);
                cur = pos[cur];
            }
        }

    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i.size() << ' ';
        for (int j : i) cout << j << ' ';
        cout << '\n';
    }
}