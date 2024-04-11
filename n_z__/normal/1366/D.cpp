#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10000001],t[10000001],ans[10000001];
void init(int mx)
{
    for(int x=2;x<=mx;x++)
    if(!t[x])
    {
        t[x]=x;
        for(int y=2*x;y<=mx;y+=x)
        t[y]=x;
    }
}
main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    init(10000000);
    for(int x=1;x<=n;x++)
    {
        cin>>a[x];
        int q=t[a[x]];
        while(a[x]%q==0)a[x]/=q;
        if(a[x]==1)cout<<-1<<' ',a[x]*=-1;
        else cout<<q<<' ';
    }
    cout<<endl;
    for(int x=1;x<=n;x++)
    cout<<a[x]<<' ';
}