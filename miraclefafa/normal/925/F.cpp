#include <bits/stdc++.h>

using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

typedef double db;
const db EPS = 1e-9;
const db inf=1e20;
inline int sign(db a) { return a < -EPS ? -1 : a > EPS; }
inline int cmp(db a, db b){ return sign(a-b); }

const int N=101000;
int ts,u[N],v[N],a[N],b[N],c[N],d[N],n,m;
typedef db flowt;
namespace flow {
	const int M=101000,N=101000;
	int y[M],nxt[M],gap[N],fst[N],c[N],pre[N],q[N],dis[N];
	int slope[M];
	flowt f[M];
	int S,T,tot,Tn;
	void init(int s,int t,int tn) {
		tot=1;
		memset(fst,0,sizeof(fst));
		S=s;T=t;Tn=tn;
	}
	void add(int u,int v,int c,flowt c1,flowt c2=0) {
		tot++;y[tot]=v;f[tot]=c1;nxt[tot]=fst[u];fst[u]=tot;
		slope[tot]=c;
		tot++;y[tot]=u;f[tot]=c2;nxt[tot]=fst[v];fst[v]=tot;
		slope[tot]=0;
	}
	flowt sap() {
		int u=S,t=1;flowt flow=0;
		rep(i,0,Tn) c[i]=fst[i],dis[i]=Tn,gap[i]=0;
		q[0]=T;dis[T]=0;pre[S]=0;
		rep(i,0,t) {
			int u=q[i];
			for (int j=fst[u];j;j=nxt[j]) if (dis[y[j]]>dis[u]+1&&fabs(f[j^1])>EPS) 
				q[t++]=y[j],dis[y[j]]=dis[u]+1;
		}
		rep(i,0,Tn) gap[dis[i]]++;
		while (dis[S]<=Tn) {
			while (c[u]&&(fabs(f[c[u]])<EPS||dis[y[c[u]]]+1!=dis[u])) c[u]=nxt[c[u]];
			if (c[u]) {
				pre[y[c[u]]]=c[u]^1;
				u=y[c[u]];
				if (u==T) {
					flowt minf=inf;
					for (int p=pre[T];p;p=pre[y[p]]) minf=min(minf,f[p^1]);
					for (int p=pre[T];p;p=pre[y[p]]) f[p^1]-=minf,f[p]+=minf;
					flow+=minf;u=S;
				}
			} else {
				if (!(--gap[dis[u]])) break;
				int mind=Tn;
				c[u]=fst[u];
				for (int j=fst[u];j;j=nxt[j]) if (fabs(f[j])>EPS&&dis[y[j]]<mind) 
					mind=dis[y[j]],c[u]=j;
				dis[u]=mind+1;
				gap[dis[u]]++;
				if (u!=S) u=y[pre[u]];
			}
		}
		q[0]=S; t=1;
		rep(i,0,Tn) dis[i]=Tn;
		dis[S]=0;
		rep(i,0,t) {
			int u=q[i];
			for (int j=fst[u];j;j=nxt[j]) if (dis[y[j]]>dis[u]+1&&fabs(f[j])>EPS) {
				dis[y[j]]=dis[u]+1;
				q[t++]=y[j];
			}
		}
		ts=0;
		rep(i,0,Tn) for (int j=fst[i];j;j=nxt[j]) if (dis[i]<Tn&&dis[y[j]]>=Tn) ts+=slope[j];
		return flow;
	}
};

db bel[N];
int sl[N];
int check(double t) {
	rep(i,1,n+1) bel[i]=0,sl[i]=0;
	flow::init(0,n+1,n+2);
	rep(i,0,m) {
		db l=a[i]*t+b[i],r=c[i]*t+d[i];
		flow::add(u[i],v[i],c[i]-a[i],r-l);
		bel[u[i]]+=l; bel[v[i]]-=l;
		sl[u[i]]+=a[i]; sl[v[i]]-=a[i];
	}
	db sf=0;
	int ss=0;
	rep(i,1,n+1) if (bel[i]>0) {
		sf+=bel[i]; flow::add(i,n+1,sl[i],bel[i]);
		ss+=sl[i];
	} else flow::add(0,i,-sl[i],-bel[i]);
	db r=flow::sap();
	if (ts==ss) {
		if (cmp(r,sf)==-1) return 2;
		else return 1;
	} else if (ts>ss) return 0;
	else return 2;
}
double gao(int ty) {
	double l=0,r=1;
	rep(it,0,30) {
		double md=(l+r)*0.5;
		if (check(md)>=ty) r=md; else l=md;
	}
	return 0.5*(l+r);
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) scanf("%d%d%d%d%d%d",u+i,v+i,a+i,b+i,c+i,d+i);
	db l=gao(1),r=gao(2);
	printf("%.10f\n",r-l);
}