//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
double a,b,c,K,res=0;
inline void dfs(double a,double b,double c,int dep,double gl)
{
	res+=gl*c*dep;if(a<1e-9&&b<1e-9) return;
//	printf("%.10Lf %.10Lf %.10Lf %d %.10Lf\n",a,b,c,dep,gl*c);
	if(a>1e-9)
	{
		if(a<K)
		{
			if(b>1e-9) dfs(0,b+a/2,c+a/2,dep+1,gl*a);
			else dfs(0,0,c+a,dep+1,gl*a);
		}
		else
		{
			if(b>1e-9) dfs(a-K,b+K/2,c+K/2,dep+1,gl*a);
			else dfs(a-K,0,c+K,dep+1,gl*a);
		}
	}
	if(b>1e-9)
	{
		if(b<K)
		{
			if(a>1e-9) dfs(a+b/2,0,c+b/2,dep+1,gl*b);
			else dfs(0,0,c+b,dep+1,gl*b);
		}
		else
		{
			if(a>1e-9) dfs(a+K/2,b-K,c+K/2,dep+1,gl*b);
			else dfs(0,b-K,c+K,dep+1,gl*b);
		}
	}
}
inline void solve()
{
	scanf("%Lf%Lf%Lf%Lf",&a,&b,&c,&K),res=0;
	dfs(a,b,c,1,1),printf("%.12Lf\n",res);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}