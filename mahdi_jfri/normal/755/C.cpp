#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e4 + 20;
int a[maxn] , res , visited[maxn] , z , k;
void dfs(int v)
{
    visited[v] = z;
    if(visited[a[v]] == 0)
        dfs(a[v]);
    else if(visited[a[v]] != z)
        k = 1;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        z++;
        k = 0;
        if(!visited[i])
        {
            dfs(i);
            if(!k)
                res++;
        }
    }
    cout << res;
}