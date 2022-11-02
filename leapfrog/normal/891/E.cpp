//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int P=1e9+7;int n,K,a[5005],b[5005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]);
	b[0]=1;for(int i=1;i<=n;i++) for(int j=i;~j;j--) b[j]=(1ll*b[j]*a[i]%P-(j?b[j-1]:0)+P)%P;
	int nw=1,res=0,iv=ksm(n);for(int i=0;i<=n;i++) (res+=1ll*b[i]*nw%P)%=P,nw=1ll*nw*(K-i)%P*iv%P;
	return printf("%d\n",(b[0]-res+P)%P),0;
}