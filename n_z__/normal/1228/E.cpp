#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=1e9+7;
int qp(int n,int k=p-2)
{
    int r=1;
    while(k)
    {
        if(k&1)(r*=n)%=p;
        k>>=1,(n*=n)%=p;
    }
    return r;
}
int fac[251],ifac[251];
void init(int n)
{
    fac[0]=1;
    for(int x=1;x<=n;x++)
    fac[x]=fac[x-1]*x%p;
    ifac[n]=qp(fac[n]);
    for(int x=n;x>=1;x--)
    ifac[x-1]=ifac[x]*x%p;
}
int C(int x,int y)
{
    return fac[x]*ifac[y]%p*ifac[x-y]%p;
}
main(){
    int n,k;
    cin>>n>>k;
    init(n);
    int ans=0;
    for(int x=0;x<=n;x++)
    (ans+=(x%2==1?-1:1)*C(n,x)*qp((qp(k,n-x)*qp(k-1,x)%p-qp(k-1,n)%p)%p,n)%p)%=p;
    cout<<(ans+p)%p<<endl;
}