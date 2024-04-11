#include<bits/stdc++.h>
using namespace std;
int g[100001],v[100001],b[100001],nowthis[100001];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int x=1;x<=n;x++)
    cin>>g[x];
    for(int x=1;x<=m;x++)
    cin>>v[x];
    for(int x=1;x<=m;x++)
    cin>>b[x];
    int lastans=0;
    for(int x=1;x<=m;x++)
    {
        int ans=0;
        for(int y=(v[x]+lastans-1)%n+1;nowthis[y]<b[x];y=g[y])
        {
            if(nowthis[y]==0)ans++;
            nowthis[y]=b[x];
            b[x]--;
        }
        lastans=ans;
        cout<<ans<<endl;
    }
}