//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int T,n,m,x,a[100005];double res,w;
int main()
{
	for(read(T);T--;)
	{
		read(n),read(m),res=1;for(int i=1;i<=n;i++) read(a[i]);
		int r=n+1;for(int i=n;i;i--) if(a[i]==i) r=i;else break;
		while(m--) {read(x),scanf("%lf",&w);if(x>=r-1) res*=1-w;}
		if(r==1) {printf("%.9lf\n",1.0);continue;}
		printf("%.9lf\n",1-res);
	}
	return 0;
}