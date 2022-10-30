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
const int N=1005;int n,K,cl[N][N],clt=0;
inline void solve(int l,int r,int dep)
{
	//printf("? %d %d\n",l,r);
	if(l>r) return;else clt=max(clt,dep);
	if(r-l+1<=K)
	{
	//	printf("! %d %d %d\n",l,r,dep);
		for(int i=l;i<=r;i++) for(int j=i+1;j<=r;j++) cl[i][j]=dep;
		return;
	}
	int lim=(r-l+K)/K;
	for(int i=0;i<K;i++) solve(i*lim+l,min(i*lim+lim+l-1,r),dep+1);
	for(int i=0;i<K;i++) for(int j=i+1;j<K;j++)
		for(int a=i*lim+l;a<=min(i*lim+lim+l-1,r);a++)
			for(int b=j*lim+l;b<=min(j*lim+lim+l-1,r);b++)
				cl[a][b]=dep;
}
int main()
{
	read(n,K),solve(1,n,1),printf("%d\n",clt);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) printf("%d ",cl[i][j]);
	//putchar('\n');for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) printf("%d%c",cl[i][j],j==n?'\n':' ');
	return putchar('\n'),0;
}