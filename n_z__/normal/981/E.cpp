#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[10001];
pair<pair<int,int>,int>a[10001];
#define l first.first
#define r first.second
#define v second
main(){
    int n,m;
    cin>>n>>m;
    for(int x=1;x<=m;x++)
    cin>>a[x].l>>a[x].r>>a[x].v;
    sort(a+1,a+1+m);
    f[0]=n;
    for(int x=1;x<=m;x++)
    for(int y=n-a[x].v;y>=0;y--)
    if(f[y]>=a[x].l)
    f[y+a[x].v]=max(f[y+a[x].v],min(f[y],a[x].r));
    int t=0;
    for(int x=1;x<=n;x++)
    t+=(f[x]>0);
    cout<<t<<endl;
    for(int x=1;x<=n;x++)
    if(f[x]>0)cout<<x<<' ';
}