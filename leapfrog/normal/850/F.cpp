#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;int mx=1e5,n,a[100005],s,f[100005],res;
inline int qpow(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	scanf("%d",&n),s=0,res=0;
	for(int i=1;i<=n;i++) scanf("%d",a+i),s+=a[i];
	f[1]=1ll*(s-1)*(s-1)%P*qpow(s)%P,f[2]=(2ll*f[1]%P-1+P)%P;
	for(int i=2;i<mx;i++) f[i+1]=((2ll*f[i]%P-f[i-1]+P)%P-1ll*(s-1)*qpow(s-i)%P+P)%P;
	for(int i=1;i<=n;i++) res=(res+f[a[i]])%P;
	return printf("%d\n",res),0;
}