#include<bits/stdc++.h>
using namespace std;
int n,a[200001],qq[200001];
bool f[200001],v[200001];
queue<int>q;
void init()
{
    q=queue<int>();
    for(int x=1;x<=n;x++)f[x]=v[x]=false;
}
int bfs()
{
    int ans=0;
    for(int x=1;x<=n;x++)
    if(!f[x])q.push(x);
    else ans++;
    for(int x=1;x<=n;x++)
    if(!v[a[x]])v[a[x]]=true,qq[a[x]]=x;
    else
    {
        int t=q.front();q.pop();
        if(t!=x)a[x]=t,qq[t]=x;
        else
        if(!q.empty())
        a[x]=q.front(),qq[q.front()]=x,q.pop(),q.push(t);
        else
        {
            int tt=a[qq[a[x]]];
            a[qq[a[x]]]=t;
            a[x]=tt;
        }
    }
    return ans;
}
void solve()
{
    cin>>n;
    init();
    for(int x=1;x<=n;x++)cin>>a[x],f[a[x]]=true;
    cout<<bfs()<<endl;
    for(int x=1;x<=n;x++)cout<<a[x]<<' ';
    cout<<endl;
}
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}