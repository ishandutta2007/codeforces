#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#define ll long long
using namespace std;
map <int,int> cur;
vector <int> avail[200001];
bool color[200001];
int n, m, k, a[200001], i, c, b, v, ans = 0, visited, maxi;
void visit(int u)
{
    visited++;
    color[u] = 1;
    maxi = max(maxi, ++cur[a[u]]);
    for (int v: avail[u]) if (!color[v]) visit(v);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    for (i = 1; i <= n; i++) cin>>a[i];
    for (i = 1; i <= m; i++)
    {
        cin>>c>>b;
        avail[c].push_back(b);
        avail[b].push_back(c);
    }
    for (i = 1; i <= n; i++)
        if (!color[i])
        {
            cur.clear();
            visited = maxi = 0;
            visit(i);
            ans += visited - maxi;
        }
    cout<<ans;
}