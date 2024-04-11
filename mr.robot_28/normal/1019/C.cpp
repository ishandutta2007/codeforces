#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
int n;
const int N = 1e6 + 1;
//#define int long long
vector <int> g[N];
bool used[N], used1[N];
vector <int> ans;
void go_to(int i)
{
    if(i == n)
    {
        return;
    }
    if(used[i])
    {
        go_to(i + 1);
        return;
    }
    for(int j = 0; j < g[i].size(); j++)
    {
        used[g[i][j]] = 1;
    }
    go_to(i + 1);
    if(!used1[i])
    {
        for(int j = 0; j < g[i].size(); j++)
        {
            used1[g[i][j]] = 1;
        }
        ans.push_back(i + 1);
    }
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }
    go_to(0);
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}