#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
typedef vector<int> vi;
const int maxn = 1e2 + 20;
vi adj[maxn];
int l[maxn] , r[maxn] , cmp[maxn] , m;
bool visited[maxn];
bool is(int x , int y)
{
    if(l[x] < l[y] && l[y] < r[x] && r[y] > r[x])
        return 1;
    if(l[y] < l[x] && l[x] < r[y] && r[x] > r[y])
        return 1;
    return 0;
}
void dfs(int v, bool c)
{
    visited[v] = 1;
    cmp[v] = c;
    for(int i = 0; i < m; i++)
    {
        if(i == v)
            continue;
        if(is(i , v) && !visited[i])
            dfs(i , 1 - c);
        else if(is(i , v) && cmp[i] == c)
        {
            cout << "Impossible";
            exit(0);
        }
    }
}
int main()
{
    int n;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        l[i] = min(a , b);
        r[i] = max(a , b);
    }
    for(int i = 0; i < m; i++)
    {
        if(!visited[i])
            dfs(i , 0);
    }
    for(int i = 0; i < m; i++)
    {
        if(cmp[i] == 1)
            cout << 'i';
        else
            cout << 'o';
    }
}