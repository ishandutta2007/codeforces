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
const int N=300005,D=22;
int n,m,fg,a[N],sz[N*22],ch[N*22][2],rt,tt;
inline void ins(int &x,int v,int d=D)
{
	sz[x?x:x=++tt]++;if(d<0) return;
	ins(ch[x][(v>>d)&1],v,d-1);
}
inline int qry(int x,int d=D)
{
	int sn;if(!x) return 0;else if(d<0) return 0;else sn=(fg>>d)&1;
	if(sz[ch[x][sn]]==(1<<d)) return qry(ch[x][sn^1],d-1)|(1<<d);else return qry(ch[x][sn],d-1);
}
int main()
{
	read(n),read(m),fg=0;for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1),n=unique(a+1,a+n+1)-a-1;for(int i=1;i<=n;i++) ins(rt,a[i]);
	for(int x;m--;) read(x),fg^=x,printf("%d\n",qry(rt));
	return 0;
}