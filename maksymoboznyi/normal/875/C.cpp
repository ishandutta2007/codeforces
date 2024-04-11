#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

vector<int> s[N], g[N];
int n, m;
bool used[N], point[N];

bool is_less(vector<int> a, vector<int> b)
{
    for (int i = 0; i < min(int(a.size()), int(b.size())); i++)
        if (a[i] < b[i])
            return true;
        else
            if (a[i] > b[i])
                return false;
    return a.size() <= b.size();
}

void dfs(int v)
{
    used[v] = true;
    point[v] = true;
    for (int i = 0; i < int(g[v].size()); i++)
        if (!used[g[v][i]])
            dfs(g[v][i]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            int a;
            cin >> a;
            s[i].pb(a);
        }
    }
    for (int i = 0; i + 1 < n; i++)
    {
        int pos = -1;
        for (int j = 0; j < min(s[i].size(), s[i+1].size()); j++)
            if (s[i][j] != s[i+1][j])
            {
                pos = j;
                break;
            }
     //   cout << pos << ' ' << i << ' '<< s[i][pos] << ' '<< s[i+1][pos] << endl;
        
        if (pos == -1)
            if (s[i].size() <= s[i+1].size())
                continue;  
            else
            { 
                cout << "No";
                return 0;
            }
        if (s[i][pos] > s[i+1][pos])
            point[s[i][pos]] = 1;
        else
            g[s[i+1][pos]].pb(s[i][pos]);
    }
    for (int i = 1; i <= m; i++)
        if (!used[i] && point[i])
            dfs(i);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < s[i].size(); j++)
            if (point[s[i][j]])
                s[i][j] -= 1e9;
    for (int i = 0; i + 1 < n; i++)
        if (!is_less(s[i], s[i+1]))
        {
            cout << "No";
            return 0;
        }
    cout << "Yes\n";
    vector<int> ans;
    ans.clear();
    for (int i = 1; i <= m; i++)
        if (point[i])
            ans.pb(i);
    cout << ans.size() << endl;
    for (int i = 0; i < int(ans.size()); i++)
        cout << ans[i] << ' ';
    return 0;
}