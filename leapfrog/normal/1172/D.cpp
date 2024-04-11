//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int N=1005;int n,a[N],b[N],ra[N],rb[N],c[N],d[N],rc[N],rd[N];
struct nd{int a,b,c,d;}r[N<<1];int rt;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(b[i]),rb[b[i]]=i,c[i]=d[i]=i;
	for(int i=1;i<=n;i++) read(a[i]),ra[a[i]]=i,rc[i]=rd[i]=i;
	//(1,i)->(n,a_i),(1,ra_i)->(n,i)
	for(int i=1;i<n;i++)
	{
		if(c[i]==ra[i]&&d[i]==rb[i]) continue;
		r[++rt]=(nd){i,rc[ra[i]],rd[rb[i]],i};int x=c[i],y=d[i];
		swap(c[i],c[rc[ra[i]]]),swap(d[i],d[rd[rb[i]]]);
		swap(rc[ra[i]],rc[x]),swap(rd[rb[i]],rd[y]);
	}
	printf("%d\n",rt);for(int i=1;i<=rt;i++) printf("%d %d %d %d\n",r[i].a,r[i].b,r[i].c,r[i].d);
	return 0;
}