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

const int inf=0x20202020;
typedef int flowt;
namespace flow {
	const int M=3000000,N=3000;
	int y[M],nxt[M],gap[N],fst[N],c[N],pre[N],q[N],dis[N],vis[N];
	flowt f[M];
	int S,T,tot,Tn;
	void init(int s,int t,int tn) {
		tot=1; assert(tn<N);
		rep(i,0,tn) fst[i]=0;
		S=s;T=t;Tn=tn;
	}
	void add(int u,int v,flowt c1,flowt c2=0) {
//		printf("add %d %d\n",u,v);
		tot++;y[tot]=v;f[tot]=c1;nxt[tot]=fst[u];fst[u]=tot;
		tot++;y[tot]=u;f[tot]=c2;nxt[tot]=fst[v];fst[v]=tot;
	}
	flowt sap() {
		int u=S,t=1;flowt flow=0;
		rep(i,0,Tn) c[i]=fst[i],dis[i]=Tn,gap[i]=0;
		q[0]=T;dis[T]=0;pre[S]=0;
		rep(i,0,t) {
			int u=q[i];
			for (int j=fst[u];j;j=nxt[j]) if (dis[y[j]]>dis[u]+1&&f[j^1]) 
				q[t++]=y[j],dis[y[j]]=dis[u]+1;
		}
		rep(i,0,Tn) gap[dis[i]]++;
		while (dis[S]<=Tn) {
			while (c[u]&&(!f[c[u]]||dis[y[c[u]]]+1!=dis[u])) c[u]=nxt[c[u]];
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
				for (int j=fst[u];j;j=nxt[j]) if (f[j]&&dis[y[j]]<mind) 
					mind=dis[y[j]],c[u]=j;
				dis[u]=mind+1;
				gap[dis[u]]++;
				if (u!=S) u=y[pre[u]];
			}
		}
		t=0; q[t++]=S; vis[S]=1;
		rep(i,0,t) {
			int u=q[i];
			for (int j=fst[u];j;j=nxt[j]) if (f[j]&&!vis[y[j]]) {
				q[t++]=y[j];
				vis[y[j]]=1;
			}
		}
		return flow;
	}
};

const int N=2100;
int n,x[N],y[N],n1,n2,crow[N],ccol[N];
PII p[N];
VI row[N],col[N];
vector<VI> srow,scol;

int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%d",x+i,y+i);
	}
	rep(i,0,n) p[i]=mp(x[i],y[i]);
	sort(p,p+n);
	rep(i,0,n) {
		srow.pb(VI{2*p[i].fi,2*p[i].se-1,2*p[i].se+1});
		scol.pb(VI{2*p[i].se,2*p[i].fi-1,2*p[i].fi+1});
	}

	rep(i,0,n-1) if (p[i].fi==p[i+1].fi) {
		row[n1++]=VI{2*p[i].fi,2*p[i].se+1,2*p[i+1].se-1};
	}

	rep(i,0,n) p[i]=mp(y[i],x[i]);
	sort(p,p+n);
	rep(i,0,n-1) if (p[i].fi==p[i+1].fi) {
		col[n2++]=VI{2*p[i].fi,2*p[i].se+1,2*p[i+1].se-1};
	}
	flow::init(n1+n2,n1+n2+1,n1+n2+2);
	rep(i,0,n1) flow::add(n1+n2,i,1);
	rep(i,0,n2) flow::add(n1+i,n1+n2+1,1);

	rep(i,0,n1) rep(j,0,n2) {
		if (row[i][1]<=col[j][0]&&col[j][0]<=row[i][2]&&col[j][1]<=row[i][0]&&row[i][0]<=col[j][2])
			flow::add(i,j+n1,1);
	}
	flow::sap();
	rep(i,0,n1) crow[i]=flow::vis[i];
	rep(i,0,n2) ccol[i]=!flow::vis[i+n1];
	rep(i,0,n1) if (crow[i]) {
		VI pl,pr;
		for (vector<VI>::iterator it=srow.begin();it!=srow.end();it++)
			if ((*it)[0]==row[i][0]&&(*it)[2]==row[i][1]) {
				pl=*it;
				srow.erase(it);
				break;
			}

		for (vector<VI>::iterator it=srow.begin();it!=srow.end();it++)
			if ((*it)[0]==row[i][0]&&(*it)[1]==row[i][2]) {
				pr=*it;
				srow.erase(it);
				break;
			}
		assert(SZ(pl)==3&&SZ(pr)==3);
		srow.pb(VI{pl[0],pl[1],pr[2]});
	}


	rep(i,0,n2) if (ccol[i]) {
		VI pl,pr;
		for (vector<VI>::iterator it=scol.begin();it!=scol.end();it++)
			if ((*it)[0]==col[i][0]&&(*it)[2]==col[i][1]) {
				pl=*it;
				scol.erase(it);
				break;
			}

		for (vector<VI>::iterator it=scol.begin();it!=scol.end();it++)
			if ((*it)[0]==col[i][0]&&(*it)[1]==col[i][2]) {
				pr=*it;
				scol.erase(it);
				break;
			}
		assert(SZ(pl)==3&&SZ(pr)==3);
		scol.pb(VI{pl[0],pl[1],pr[2]});
	}
	printf("%d\n",SZ(scol));
	for (auto p:scol) printf("%d %d %d %d\n",(p[1]+1)/2,p[0]/2,(p[2]-1)/2,p[0]/2);
	printf("%d\n",SZ(srow));
	for (auto p:srow) printf("%d %d %d %d\n",p[0]/2,(p[1]+1)/2,p[0]/2,(p[2]-1)/2);

}