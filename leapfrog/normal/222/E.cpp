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
long long n;int m,k,rs=0;
struct matrix
{
	int a[53][53];
	inline void clr0() {memset(a,0,sizeof(a));}
	inline void clr1() {clr0();for(int i=1;i<=m;i++) a[i][i]=1;}
	inline void clra() {for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) a[i][j]=1;}
	inline matrix operator*(matrix b)
	{
		matrix a=*this,r;r.clr0();
		for(int i=1;i<=m;i++) for(int k=1;k<=m;k++) for(int j=1;j<=m;j++) (r.a[i][j]+=1ll*a.a[i][k]*b.a[k][j]%P)%=P;
		return r;
	}
	inline matrix operator^(long long q) {matrix x=*this,r;r.clr1();for(;q;q>>=1,x=x*x) if(q&1) r=r*x;return r;}
}mx;
inline int ID(char c) {if(c>='A'&&c<='Z') return 27+c-'A';else return 1+c-'a';}
int main()
{
	read(n),read(m),read(k),mx.clra();char c[3];
	for(int i=1;i<=k;i++) scanf("%s",c+1),mx.a[ID(c[1])][ID(c[2])]=0;
	mx=mx^(n-1);for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) (rs+=mx.a[i][j])%=P;
	return printf("%d\n",rs),0;
}