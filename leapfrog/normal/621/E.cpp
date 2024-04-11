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
int n,b,p,r,cnt[105];
struct mat
{
	int a[105][105];
	inline void clear() {memset(a,0,sizeof(a));}
	inline void clear1() {clear();for(int i=0;i<p;i++) a[i][i]=1;}
	inline mat operator*(const mat &b)
	{
		mat r;r.clear();
		for(int i=0;i<p;i++) for(int k=0;k<p;k++) for(int j=0;j<p;j++) (r.a[i][j]+=1ll*a[i][k]*b.a[k][j]%P)%=P;
		return r;
	}
	inline mat operator^(int q) {mat r,x=*this;r.clear1();for(;q;q>>=1,x=x*x) if(q&1) r=r*x;return r;}
}q;
int main()
{
	read(n),read(b),read(r),read(p);int res=0;
	for(int i=1,x;i<=n;i++) read(x),cnt[x%p]++;
	for(int i=0;i<p;i++) for(int s=0;s<p;s++) q.a[s][(s*10+i)%p]=cnt[i];
	// for(int i=0;i<p;i++) for(int j=0;j<p;j++) printf("%d%c",q.a[i][j],j==p-1?'\n':' ');
	q=q^b,res=q.a[0][r];
	// for(int i=0;i<p;i++) for(int j=0;j<p;j++) printf("%d%c",q.a[i][j],j==p-1?'\n':' ');
	return printf("%d\n",res),0;
}