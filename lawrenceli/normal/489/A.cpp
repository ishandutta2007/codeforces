#include <bits/stdc++.h>

using namespace std;

int n;
bool vis[3005];
pair<int, int> a[3005];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a+n);

    vector<pair<int, int> > ans;
    for (int i=0; i<n; i++)
        if (!vis[i]) {
            int cur = i;
            do {
                vis[cur] = 1;
                if (a[cur].second != i)
                    ans.push_back(make_pair(cur, a[cur].second));
                cur = a[cur].second;
            } while (cur != i);
        }

    cout << ans.size() << '\n';
    for (int i=0; i<ans.size(); i++)
        cout << ans[i].first << ' ' << ans[i].second << '\n';
}