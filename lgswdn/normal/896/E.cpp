// LUOGU_RID: 96606290
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define fi first
#define se second
#define eb emplace_back
#define bp __builtin_parity
#define y1 yyl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

int read() {
	int x=0,w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {x=x*10+c-'0'; c=getchar();}
	return x*w;
}

const int N=1e6+9;
int n,m,a[N],bs,b[N],bl[N],br[N],op[N],l[N],r[N],x[N],ans[N],st[N],top;

int rt[N],id[N],s[N],c[N];
inline int find(int x) {return x==id[x]?x:id[x]=find(id[x]);}
inline void merge(int x,int y) { // colour x -> colour y
	if(!rt[y]) rt[y]=rt[x], c[rt[x]]=y, s[y]=s[x], s[x]=0, rt[x]=0;
	else id[rt[x]]=rt[y], c[rt[x]]=0, s[y]+=s[x], s[x]=0, rt[x]=0;
}
inline void reconstruct_a(int l,int r) {
	rep(i,l,r) if(a[i]) a[i]=c[find(i)];
	rep(i,l,r) rt[a[i]]=s[a[i]]=c[a[i]]=0;
}
inline void reconstruct_p(int l,int r) {
	rep(i,l,r) {
		if(!rt[a[i]]) rt[a[i]]=i, c[i]=a[i], s[a[i]]=1, id[i]=i;
		else if(a[i]) id[i]=rt[a[i]], s[a[i]]++;
	}
}

void work(int p) {
	reconstruct_p(bl[p],br[p]);
	int tag=0, mx=0, s0=0, ymx=0;
	rep(i,bl[p],br[p]) mx=max(mx,a[i]), s0+=(!a[i]);
	ymx=mx;
	rep(i,1,m) {
		if(r[i]<bl[p]||l[i]>br[p]) continue;
		if(op[i]==1) {
			if(x[i]==0||x[i]+tag>100001);
			else if(l[i]<=bl[p]&&br[p]<=r[i]) {
				if(mx<=x[i]);
				else if(mx<=2*x[i]) {
					rep(j,x[i]+1,mx) if(rt[j+tag]) merge(j+tag,j-x[i]+tag);
					mx=x[i];
				} else {
					rep(j,1,x[i]) if(rt[j+tag]) merge(j+tag,j+x[i]+tag);
					mx-=x[i], tag+=x[i];
				}
			} else {
				reconstruct_a(bl[p],br[p]);
				int u=max(l[i],bl[p]), v=min(r[i],br[p]);
				rep(j,u,v) if(a[j]-tag>x[i]) a[j]-=x[i];
				reconstruct_p(bl[p],br[p]);
			}
		} else {
			if(l[i]<=bl[p]&&br[p]<=r[i]) {
				if(x[i]==0) ans[i]+=s0;
				else ans[i]+=s[x[i]+tag];
			} else {
				int u=max(l[i],bl[p]), v=min(r[i],br[p]);
				if(x[i]==0) {
					rep(j,u,v) ans[i]+=!a[j];
				} else if(s[x[i]+tag]) {
					rep(j,u,v) ans[i]+=(c[find(j)]-tag==x[i]);
				}
			}
		}
	}
	rep(i,bl[p],br[p]) id[i]=i, c[i]=0;
	rep(i,1,ymx) rt[i]=s[i]=0;
}

signed main() {
	n=read(), m=read(), bs=1270;
	rep(i,1,n) a[i]=read();
	rep(i,1,n) {
		b[i]=(i-1)/bs+1;
		if(!bl[b[i]]) bl[b[i]]=i;
		br[b[i]]=i;
	}
	rep(i,1,m) op[i]=read(), l[i]=read(), r[i]=read(), x[i]=read();
	rep(i,1,b[n]) work(i);
	rep(i,1,m) if(op[i]==2) printf("%d\n",ans[i]);
	putchar('\n');
	return 0;
}