//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}/*}}}*/
int n,st[300005],tp,rst=0;struct rsn{int x,y,w;}rs[1500005];
struct node{int vl,id;char operator<(node b) const {return vl<b.vl;}}a[300005],b[300005];
inline void ins(int x,int y,int w) {rs[++rst]=(rsn){a[x].id,a[y].id,w};}
inline void flush() {printf("%d\n",rst);for(int i=1;i<=rst;i++) printf("%d %d %d\n",rs[i].y,rs[i].x,rs[i].w);}
int main()
{
	read(n);ll nw=0;for(int i=1;i<=n;i++) read(a[i].vl),a[i].id=i;
	sort(a+1,a+n+1);for(int i=1;i<=n;i++) read(b[i].vl),b[i].id=i;
	sort(b+1,b+n+1);for(int i=1;i<=n;i++) {nw+=b[i].vl-a[i].vl;if(nw<0) return puts("NO"),0;}
	if(nw) return puts("NO"),0;else puts("YES");
	//for(int i=1;i<=n;i++) printf("%d%c",a[i].vl,i==n?'\n':' ');
	//for(int i=1;i<=n;i++) printf("%d%c",b[i].vl,i==n?'\n':' ');
	for(int i=1;i<=n;i++)
		if(a[i].vl<b[i].vl) st[++tp]=i;
		else if(a[i].vl^b[i].vl) while(tp)
		{
			int x=min(a[i].vl-b[i].vl,b[st[tp]].vl-a[st[tp]].vl);
			//printf("ins %d %d %d\n",i,st[tp],x);
			a[i].vl-=x,a[st[tp]].vl+=x,ins(i,st[tp],x);if(a[i].vl^b[i].vl) tp--;else break;
		}
	return flush(),0;
}