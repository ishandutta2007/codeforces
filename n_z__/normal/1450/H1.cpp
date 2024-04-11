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
int fac[200001],ifac[200001];
void init(int n)
{
    fac[0]=1;
    for(int x=1;x<=n;x++)
    fac[x]=fac[x-1]*x%p;
    ifac[n]=qp(fac[n]);
    for(int x=n;x>=1;x--)
    ifac[x-1]=ifac[x]*x%p;
}
main(){
	int n,m;
    cin>>n>>m;
    init(n);
    int c=n/2,s=0;
    for(int x=1;x<=n;x++)
    {
        char ch;
        cin>>ch;
        c-=((ch=='w')&&(x&1))||((ch=='b')&&!(x&1));
        s+=(ch=='?');
    }
    int ans=0;
	for(int x=c&1;x<=s;x+=2)
    (ans+=abs(c-x)*fac[s]%p*ifac[x]%p*ifac[s-x]%p)%=p;
    cout<<ans*qp(2,s*(p-2)%(p-1))%p;
}