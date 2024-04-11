#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[501],b[501],c[501],d[501],f[501][501];
main()
{
    int n,m;
    cin>>n>>m;
    for(int x=1;x<=n;x++)
    cin>>a[x]>>b[x];
    for(int x=1;x<=m;x++)
    cin>>c[x]>>d[x];
    for(int x=1;x<=n;x++)
    for(int y=1;y<=n;y++)
    if(a[x]<a[y])
    {
        int u=b[y]-b[x],v=a[x]-a[y],w=-a[x]*u-b[x]*v;
        for(int z=1;z<=m;z++)
        f[x][y]+=(c[z]>a[x]&&c[z]<=a[y]&&u*c[z]+v*d[z]+w>0);
        f[y][x]=-f[x][y];
    }
    /*for(int x=1;x<=n;x++){
    for(int y=1;y<=n;y++)
    cout<<f[x][y]<<' ';cout<<endl;}*/
    int ans=0;
    for(int x=1;x<=n;x++)
    for(int y=x+1;y<=n;y++)
    for(int z=y+1;z<=n;z++)
    ans+=(f[x][y]+f[y][z]+f[z][x]==0/*&&(cout<<x<<','<<y<<','<<z<<endl,1)*/);
    cout<<ans<<endl;
}