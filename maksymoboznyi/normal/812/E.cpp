#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

vector<int> g[100005];
long long n, a[100005], b, kol[2];
long long is[2][10000007];
bool color[100005];

void dfs(int v, int c)
{
    color[v] = c;
    kol[c]++;
    for (int i = 0; i < int(g[v].size()); i++)
        dfs(g[v][i], !c);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        cin >> b;
        g[b].pb(i);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        if (g[i].size() == 0 && color[i] == 1)
         {
             for (int j = 1; j <= n; j++)
                color[j] = !color[j];
            swap(kol[0], kol[1]);
         }
    long long s = 0;
    for (int i = 1; i <= n; i++)
        if (color[i] == 0)
            s = s ^ a[i];
    for (int i = 1; i <= n; i++)
        is[color[i]][a[i]]++;
  //  cout << 1;
    if (s == 0)
    {
       long long  ans = kol[0]*(kol[0]-1)/2 + kol[1]*(kol[1]-1)/2;
        for (int u = 1; u <= 10000000; u++)
            ans += is[0][u]*is[1][u];
        cout << ans;
        return 0;
    }
    long long ans = 0;
    int y;
    for(long long u = 1; u <= 10000000; u++)
    {
        y = s^u;
        if (y <= 10000000)
            ans += is[0][u]*is[1][s^u];

        //cout << s << ' ' << u << ' ' << y << endl;
    }
    cout << ans;
    return 0;
}