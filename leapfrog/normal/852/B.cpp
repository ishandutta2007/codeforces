//
//
#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,l,m,s[105],t[105],q[105],w[105],g[105],qwq[1000005];
struct mat
{
	int a[105][105];
	inline void clear() {memset(a,0,sizeof(a));}
	inline void clear1() {clear();for(int i=0;i<m;i++) a[i][i]=1;}
	inline mat operator*(mat b)
	{
		mat a=*this,r;r.clear();
		for(int i=0;i<m;i++) for(int k=0;k<m;k++) for(int j=0;j<m;j++) (r.a[i][j]+=1ll*a.a[i][k]*b.a[k][j]%P)%=P;
		return r;
	}
	inline mat ksm(int q) {mat x=*this,r;r.clear1();for(;q;q>>=1,x=x*x) if(q&1) r=r*x;return r;}
}mt;
int main()
{
	read(n),read(l),read(m);for(int i=1,v;i<=n;i++) read(v),++s[v];
	for(int i=1;i<=n;i++) read(qwq[i]),++q[qwq[i]];
	for(int i=1,v;i<=n;i++) read(v),++t[(v+qwq[i])%m];
	for(int i=0;i<m;i++) for(int j=0;j<m;j++) (g[(i+j)%m]+=1ll*s[i]*t[j]%P)%=P;
	mt.clear();for(int i=0;i<m;i++) for(int j=0;j<m;j++) mt.a[j][(j+i)%m]=q[i];mt=mt.ksm(l-2);
	int rs=0;for(int i=0;i<m;i++) (rs+=1ll*mt.a[i][0]*g[i]%P)%=P;
	return printf("%d\n",rs),0;
}