#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

pair<int, string> u, v;
map<pair<int, string>, vector<pair<int, string>>> adj;
map<string, bool> vis;
vector<pair<int, string>> cur, tmp, ans;
int n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> u.second >> u.first >> k;
        while (k--)
        {
            cin >> v.second >> v.first;
            adj[u].push_back(v);
        }
        if (i == 0)
            tmp.push_back(u);
    }
    int st = 0;
    while (!tmp.empty())
    {
        while (!tmp.empty())
        {
            cur.push_back(tmp.back());
            tmp.pop_back();
        }
        sort(cur.begin(), cur.end());
        while (!cur.empty())
        {
            u = cur.back();
            cur.pop_back();
            if (vis[u.second])
                continue;
            vis[u.second] = true;
            if (st > 0)
                ans.push_back(u);
            for (pair<int, string> v : adj[u])
                if (!vis[v.second])
                    tmp.push_back(v);
        }
        ++st;
    }
    sort(ans.begin(), ans.end(), [](const pair<int, string> &a, const pair<int, string> &b) { return a.second < b.second; });
    cout << ans.size() << '\n';
    for (pair<int, string> u : ans)
        cout << u.second << " " << u.first << endl;
}