#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=998244353;
int f[1145140];
main(){
    int n,a0,x,y,k,M;
    cin>>n>>a0>>x>>y>>k>>M;
    int l=1,q=k;
    for(int i=1;i<k;i++)
    l=l*i/__gcd(l,i),(q*=n)%=p;
    for(int i=k,w=1;i>=1;i--)
    {
        for(int j=l-1;j>=0;j--)
        f[j]=(f[j]*(n-1)+f[j/i*i]+j*w)%p;
        (w*=n)%=p;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    (ans+=f[a0%l]+a0/l*l*q)%=p,((a0*=x)+=y)%=M;
	cout<<ans<<endl;
}