#include<bits/stdc++.h>
using namespace std;
#define int long long
int r[200001];
int p=1e9+7;
int fac[200001],inv[200001];
int qp(int x,int n=p-2,int mod=p)
{
    int ret=1;
    while(n){
        if(n&1)ret*=x,ret%=mod;
        n>>=1;
        x*=x;
        x%=mod;
    }
    return ret;
}
void init(int n)
{
    fac[0]=inv[0]=1;
    for(int x=1;x<=n;x++)
    fac[x]=fac[x-1]*x%p,inv[x]=inv[x-1]*qp(x)%p;
}
int C(int x,int y)
{
    return fac[y]*inv[x]%p*inv[y-x]%p;
}
main(){
    string s;
    cin>>s;
    int n=s.size();
    init(n);
    s='0'+s;
    for(int x=n;x>=1;x--)
    r[x]=r[x+1]+(s[x]==')');
    int nowl=0,ans=0;
    for(int x=1;x<=n;x++)
    if(s[x]=='(')
    {
        nowl++;
        ans+=C(nowl,nowl+r[x]-1);
        ans%=p;
    }
    cout<<ans<<endl;
}