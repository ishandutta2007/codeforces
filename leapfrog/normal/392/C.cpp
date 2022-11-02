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
const int P=1e9+7;int N;
struct mat
{
	int a[85][85];inline int* operator[](int k) {return a[k];}
	inline void operator!() {memset(a,0,sizeof(a));}
	inline void operator~() {!*this;for(int i=0;i<=N;i++) a[i][i]=1;}
	inline mat operator*(const mat &b) const
	{
		mat r;!r;
		for(int i=0;i<=N;i++) for(int k=0;k<=N;k++) for(int j=0;j<=N;j++) (r.a[i][j]+=1ll*a[i][k]*b.a[k][j]%P)%=P;
		return r;
	}
	inline mat operator^(ll q) {mat x=*this,r;~r;for(;q;q>>=1,x=x*x) if(q&1) r=r*x;return r;}
}a,b;ll n;int K,pw[55],C[55][55],id[2][55];
int main()
{
	read(n),read(K),N=2*K+2,a[N][N]=1;int cnt=0;
	pw[0]=1;for(int i=1;i<=K+1;i++) pw[i]=(pw[i-1]<<1)%P;
	for(int i=0;i<=K;i++) {C[i][0]=1;for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;}
	for(int i=0;i<2;i++) for(int j=0;j<=K;j++) id[i][j]=cnt++;
	for(int i=0;i<=K;i++)
	{
		for(int j=0;j<=i;j++) a[id[0][j]][id[0][i]]=C[i][j],a[id[1][j]][id[0][i]]=1ll*C[i][j]*pw[i-j]%P;
		a[N][id[0][i]]=pw[i]+1,a[id[0][i]][id[1][i]]=1;
	}
	b[0][N]=1;for(int i=0;i<=K;i++) b[0][id[0][i]]=pw[i+1]+1,b[0][id[1][i]]=1;
	if(n==1) return printf("%d\n",b[0][id[1][K]]),0;
	return a=a^(n-2),b=b*a,printf("%d\n",b[0][id[0][K]]),0;
}