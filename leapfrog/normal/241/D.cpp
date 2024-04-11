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
int a[55],n,P,m,b[55],k,p[55];
inline void solve(int nw,int vp,int vx)
{
	if(nw==m+1)
	{
		if(vp!=0||vx!=0||!k) return;else printf("Yes\n%d\n",k);
		for(int j=1;j<=k;j++) printf("%d%c",b[j],j==k?'\n':' ');
		exit(0);
	}
	b[++k]=p[nw],solve(nw+1,(vp*(9<a[nw]?100:10)+a[nw])%P,vx^a[nw]);
	b[k--]=0,solve(nw+1,vp,vx);
}
int main()
{
	read(n,P);for(int i=1,x;i<=n;i++) {read(x);if(x<25) a[++m]=x,p[m]=i;}
	return solve(1,0,0),puts("No"),0;
}