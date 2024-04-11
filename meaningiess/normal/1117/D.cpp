#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
ll T,n,M;
struct mat {ll num[111][111];};mat t,res;
mat mul (mat x,mat y)
{
    mat res;
    memset(res.num,0,sizeof(res.num));
    for(ll i=0;i<M;i++)
        for(ll j=0;j<M;j++)
            for(ll k=0;k<M;k++) (res.num[i][j]+=x.num[i][k]*y.num[k][j])%=MOD;
    return res;
}
int main()
{
    cin>>n>>M;
    for (ll i=0;i<M-1;i++) t.num[i][i+1]=1;t.num[0][0]=t.num[M-1][0]=1;res.num[0][0]=1;
    while(n)
    {
        if(n&1) res=mul(res,t);
        t=mul(t,t);
        n>>=1;
    }cout<<res.num[0][0];
}