#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    vector<pii> r;
    vector<bool> used(300001, false);
    vector<int> ans;
    for (int qq = 0; qq < T; qq++) {
        int n, m;
        cin >> n >> m;
        int u, v;
        r.clear();
        for (int i = 1; i <= m; i++) {
            cin >> u >> v;
            r.push_back(pii(u,v));
        }
        ans.clear();
        for (int i = 0; i < m; i++) {
            if (used[r[i].first] || used[r[i].second])
                continue;
            used[r[i].first] = true;
            used[r[i].second] = true;
            ans.push_back(i+1);
        }
        int cou = 0;
        int cur = 0;
        if (ans.size() >= n) {
            cout << "Matching" << '\n';
            for (int i = 0; i < n; i++)
                cout << ans[i] << " ";
            cout << '\n';
        }
        else {
            cout << "IndSet" << '\n';
            while (cou < n) {
                cur++;
                if (used[cur])
                    continue;
                cou++;
                cout << cur << " ";
            }
            cout << '\n';
        }
        for (int i = 0; i < ans.size(); i++) {
            used[r[ans[i]-1].first] = false;
            used[r[ans[i]-1].second] = false;
        }
    }
    return 0;
}