#include<bits/stdc++.h>
using namespace std;
vector<int>v[200001];
int t[200001],a[200001][2];
void dfs(int x,int y)
{
    if(t[x]>=0)return;
    t[x]=y;
    for(auto q:v[x])
    dfs(q,!y);
}
main()
{
    int n;
    cin>>n;
    memset(t,-1,sizeof(t));
    for(int x=1;x<=n;x++)
    for(int y=0;y<=1;y++)
    {
        int qwq;
        cin>>qwq;
        if(a[qwq][y])v[x].push_back(a[qwq][y]),v[a[qwq][y]].push_back(x),a[qwq][y]=0;
        else a[qwq][y]=x;
    }
    for(int x=1;x<=n;x++)
    dfs(x,0),cout<<"br"[t[x]];
}