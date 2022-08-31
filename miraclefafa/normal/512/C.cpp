#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const ll N=1000000;
int pr[N/5],p[N+100],tot,mu[N+100];
ll mul(ll a,ll b) { return (a%mod)*(b%mod)%mod;}
void init() {
	mu[1]=1;p[1]=1;
	rep(i,2,N+1) {
		if (!p[i]) p[i]=i,pr[++tot]=i,mu[i]=-1;
		for (int j=1;j<=tot&&pr[j]*i<=N;j++) {
			p[i*pr[j]]=pr[j];
			if (p[i]==pr[j]) break;
			else mu[i*pr[j]]=-mu[i];
		}
	}
}

const int inf=0x20202020;
typedef int flowt;
namespace flow {
	const int M=100000,N=1000;
	int y[M],nxt[M],gap[N],fst[N],c[N],pre[N],q[N],dis[N];
	flowt f[M];
	int S,T,tot,Tn;
	void init(int s,int t,int tn) {
		tot=1; assert(tn<N);
		rep(i,0,tn) fst[i]=0;
		S=s;T=t;Tn=tn;
	}
	void add(int u,int v,flowt c1,flowt c2=0) {
//		printf("%d %d %d\n",u,v,c1);
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
		return flow;
	}
};

const int M=300;
int n,a[M],vis[M];
VI e[M],pth;
vector<VI> ans;
void dfs(int x) {
	vis[x]=1;
	pth.pb(x);
	rep(i,0,SZ(e[x])) {
		int v=e[x][i];
		if (!vis[v]) dfs(v);
	}
}
int main() {
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	flow::init(n,n+1,n+2);
	rep(i,0,n) if (a[i]%2==0) flow::add(n,i,2); else flow::add(i,n+1,2);
	init();
	rep(i,0,n) rep(j,0,n) if (a[i]%2==0&&a[j]%2==1) {
		if (p[a[i]+a[j]]==a[i]+a[j]) flow::add(i,j,1);
	}
	if (flow::sap()!=n) {
		printf("Impossible");
		return 0;
	}
	rep(i,0,n) if (a[i]%2==0) {
		for (int j=flow::fst[i];j;j=flow::nxt[j]) {
			int v=flow::y[j];
//			printf("%d %d %d\n",i,v,flow::f[j]);
			if (flow::f[j]==0&&0<=v&&v<n) {
//				printf("%d %d\n",i,v);
				e[i].pb(v),e[v].pb(i);
			}
		}
	}
	rep(i,0,n) assert(SZ(e[i])==2);
	rep(i,0,n) if (!vis[i]) {
		pth.clear();
		dfs(i);
		ans.pb(pth);
	}
	printf("%d\n",SZ(ans));
	rep(i,0,SZ(ans)) {
		printf("%d",SZ(ans[i]));
		for (auto p:ans[i]) printf(" %d",p+1);
		puts("");
	}
}