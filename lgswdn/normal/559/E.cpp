#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=509;

int n,p[N],s[N],pp[N],ss[N],tot,b[N],len[N],l[N],r[N],id[N],g[N],f[N][N];

bool cmpp(int x,int y) {return pp[x]<pp[y];}
int d(int x,int y) {return max(0ll,b[y]-b[x]);}

signed main() {
	n=read();
	rep(i,1,n) pp[i]=read(), ss[i]=read(), id[i]=i;
	sort(id+1,id+n+1,cmpp);
	rep(i,1,n) p[i]=pp[id[i]], s[i]=ss[id[i]];
	rep(i,1,n) {
		l[i]=p[i]-s[i], r[i]=p[i]+s[i];
		b[++tot]=l[i], b[++tot]=r[i], b[++tot]=p[i];
	}
	sort(b+1,b+tot+1); tot=unique(b+1,b+tot+1)-b-1;
	rep(i,1,n) {
		p[i]=lower_bound(b+1,b+tot+1,p[i])-b;
		l[i]=lower_bound(b+1,b+tot+1,l[i])-b;
		r[i]=lower_bound(b+1,b+tot+1,r[i])-b;
	}
	rep(i,1,n) {
		rep(j,1,tot) f[i][j]=f[i-1][j], g[j]=0;
		int x=p[i]; g[x]=f[i-1][l[i]]+d(l[i],p[i]);
		per(k,i-1,1) x=max(x,r[k]), g[x]=max(g[x],f[k-1][l[i]]+d(l[i],x));
		per(j,tot,l[i]) f[i][j]=max(f[i][j],g[j]), g[j-1]=max(g[j-1],g[j]-d(j-1,j));
		rep(j,p[i],r[i]) f[i][j]=max(f[i][j],f[i-1][p[i]]+d(p[i],j));
		rep(j,1,tot) f[i][j]=max(f[i][j],f[i][j-1]);
	}
	printf("%lld\n",f[n][tot]);
	return 0;
}