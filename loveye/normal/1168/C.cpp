#include<cstdio>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=3e5+5;
int n,m,a[N],ans[N];
int G[20][20],tG[20][20];
struct Query {
	int l,r,id;
} q[N];
int main() {
	scanf("%d%d",&n,&m);
	fr(i,1,n) scanf("%d",a+i);
	fr(i,1,m) scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+m+1,[](const Query &a,const Query &b) {
		return a.r<b.r;
	});
	int p=1;
	fr(i,1,n) {
		memset(tG,0,sizeof tG);
		fo(j,0,20) if(a[i]>>j&1) {
			fo(k,0,20) {
				if(a[i]>>k&1) tG[j][k]=i;
				else fo(p,0,20) if(a[i]>>p&1)
					tG[j][k]=max(tG[j][k],G[p][k]);
			}
		}
		fo(j,0,20) fo(k,0,20) G[j][k]=max(G[j][k],tG[j][k]);
		for(;p<=m&&q[p].r==i;++p) {
			int ok=0;
			fo(j,0,20) if(!ok&&(a[q[p].r]>>j&1)) fo(k,0,20) if(!ok&&(a[q[p].l]>>k&1))
				if(G[j][k]>=q[p].l) {
					ok=1; break;
				}
			ans[q[p].id]=ok;
		}
	}
	fr(i,1,m) puts(ans[i]?"Shi":"Fou");
	return 0;
}

const int S=1<<21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}