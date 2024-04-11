//
//
#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,S[4005][4005],fc[4005],iv[4005],B[4005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline int C(int n,int m) {return 1ll*fc[n]*iv[m]%P*iv[n-m]%P;}
int main()
{
	read(n),iv[0]=fc[0]=1;int res=0;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	iv[n]=ksm(fc[n]),S[0][0]=1;for(int i=n-1;i;i--) iv[i]=1ll*iv[i+1]*(i+1)%P;
	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) S[i][j]=(S[i-1][j-1]+1ll*S[i-1][j]*j%P)%P,(B[i]+=S[i][j])%=P;
	for(int i=0;i<n;i++) res=(res+1ll*B[i]*C(n,i)%P)%P;
	return printf("%d\n",(res+1)%P),0;
}