#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=998244353;
int qp(int x,int n=p-2)
{
    int ret=1;
    while(n)
    {
        if(n&1)ret=ret*x%p;
        x=x*x%p,n>>=1;
    }
    return ret;
}
main()
{
    int n,m;
    cin>>n>>m;
    int ans=(n+m+1)*qp(m+1)%p;
    int H=0;
    for(int x=1;x<=n;x++)
    H=(H+qp(x))%p;
    ans=ans*(H*m%p+1)%p;
    cout<<ans<<endl;
}