#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn=1e3+20;
int x[maxn],y[maxn];
int n;
bool visited[maxn];
void dfs(int v)
{
    visited[v] = 1;
    for(int i = 0 ; i < n ; i++)
    {
        if(!visited[i] && (x[v] == x[i] || y[i] == y[v]))
            dfs(i);
    }
}
ll cmp;
int main()
{
    cin >> n;
    for(int i = 0 ; i < n ;i++)
    {
        cin >> x[i] >> y[i];
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            cmp++;
        }
    }
    cout << cmp - 1;
}