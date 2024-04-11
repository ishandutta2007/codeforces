#include <bits/stdc++.h>
using namespace std;
#define N 505
#define ll long long
#define MOD 1000000007
int n1,n2,up,a1[N],a2[N];ll m;
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
void W(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;}
struct Poly
{
	int n,a[N];
	Poly operator + (Poly t) const
	{
		Poly res;res.n=max(n,t.n);
		for(int i=0;i<res.n;++i) res.a[i]=0;
		for(int i=0;i<n;++i) W(res.a[i],a[i]);
		for(int i=0;i<t.n;++i) W(res.a[i],t.a[i]);return res;
	}
	Poly operator * (Poly t) const
	{
		Poly res;res.n=n+t.n-1;
		for(int i=0;i<res.n;++i) res.a[i]=0;
		for(int i=0;i<n;++i) for(int j=0;j<t.n;++j)
			W(res.a[i+j],1ll*a[i]*t.a[j]%MOD);return res;
	}
	Poly operator % (Poly t) const
	{
		Poly res=*this;
		for(int i=res.n-1;i>=t.n-1;--i) for(int j=0;j<t.n-1;++j)
			W(res.a[i-t.n+j+1],MOD-1ll*res.a[i]*t.a[j]%MOD);
		res.n=min(res.n,t.n-1);return res;
	}
}one,X,A,P;
Poly qPow(Poly x,ll y)
{Poly res=one;for(;y;y/=2,x=x*x%P) if(y&1) res=res*x%P;return res;}
int main()
{
	scanf("%d %d %lld",&n1,&n2,&m);one.n=one.a[0]=1;X.n=2;X.a[1]=1;
	for(int i=1;i<=n1;++i) scanf("%d",&a1[i]);
	for(int i=1;i<=n2;++i) scanf("%d",&a2[i]),up=max(up,a2[i]);
	P.n=up+1;P.a[up]=1;for(int i=1;i<=n2;++i) ++P.a[up-a2[i]];
	for(int i=0;i<up;++i) P.a[i]=add(MOD-P.a[i],0);
	for(int i=1;i<=n1;++i) A=A+qPow(X,a1[i]);
	A=qPow(A,m)*qPow(X,up-1)%P;printf("%d\n",A.a[up-1]);return 0;
}