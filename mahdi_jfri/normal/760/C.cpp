#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
int p[maxn] , res , ans;
bool b[maxn] , visited[maxn] , x;
void dfs(int v)
{
    if(visited[v])
        return;
    visited[v] = 1;
    dfs(p[v]);
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i] , x ^= b[i];
    for(int i = 1; i <= n; i++)
        if(!visited[i])
            dfs(i) , res++;
    if(res == 2)
        ans = 2;
    else if(res == 1)
        ans = 0;
    else
        ans = res;
    ans += !x;
    cout << ans;
}