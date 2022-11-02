//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
const int N=1005;int n;
struct $
{
	int a,b,c,d,e;
	inline $ operator-($ x) {return ($){a-x.a,b-x.b,c-x.c,d-x.d,e-x.e};}
	inline int operator*($ x) {return a*x.a+b*x.b+c*x.c+d*x.d+e*x.e;}
}a[N];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i].a,a[i].b,a[i].c,a[i].d,a[i].e);
	vector<int>v;for(int i=1;i<=n;i++)
	{
		char fg=1;
		for(int x=1;x<=n&&fg;x++) if(x^i) for(int y=x+1;y<=n&&fg;y++)
			if(y^i) if((a[x]-a[i])*(a[y]-a[i])>0) {fg=0;break;}
		if(fg) v.push_back(i);
	}printf("%d\n",(int)v.size());
	for(auto x:v) printf("%d ",x);
	return 0;
}