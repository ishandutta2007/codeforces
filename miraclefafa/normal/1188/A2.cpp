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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1010;

int n,u,v,w,alive[N],st[N];
map<int,int> e[N];
vector<VI> ans;
VI pt[10];
int ww[10],lv[10],c,br[10];

void dfs(int u,int f,int dep) {
	st[dep]=u;
	if (SZ(e[u])==1) {
		pt[c]=VI(st,st+dep+1);
		return;
	}
	for (auto p:e[u]) {
		int v=p.fi;
		if (v==f) continue;
		dfs(v,u,dep+1);
		return;
	}
}

int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d%d",&u,&v,&w);
		e[u][v]=w;
		e[v][u]=w;
	}
	rep(i,1,n+1) alive[i]=1;
	rep(i,1,n+1) if (SZ(e[i])==2) {
		puts("NO");
		return 0;
	}
	puts("YES");
	while (1) {
		VI l;
		rep(i,1,n+1) if (alive[i]) l.pb(i);
		if (SZ(l)==2) {
			ans.pb(VI{l[0],l[1],e[l[0]][l[1]]});
			break;
		}
		int lf=-1;
		for (auto i:l) if (SZ(e[i])==1) {
			lf=i; break;
		}
		int np=e[lf].begin()->fi;
		c=0;

//		printf("%d %d\n",lf,np);

		for (auto p:e[np]) {
			int v=p.fi;
			if (v!=lf) continue;
			ww[c]=p.se;
			pt[c].clear();
			dfs(v,np,0);
			br[c]=v;
			lv[c]=pt[c].back();
			c++;
			if (c>=3) break;
		}

		for (auto p:e[np]) {
			int v=p.fi;
			if (v==lf) continue;
			ww[c]=p.se;
			pt[c].clear();
			st[0]=np;
			dfs(v,np,1);
			br[c]=v;
			lv[c]=pt[c].back();
			c++;
			if (c>=3) break;
		}

		int s=(ww[0]+ww[1]+ww[2])/2;
		int w01=s-ww[2],w02=s-ww[1];
		auto del=[&](VI &a,int b) {
			rep(i,0,SZ(a)-1) {
				int u=a[i],v=a[i+1];
				assert(e[u].count(v));
				assert(e[v].count(u));
				e[u][v]-=b;
				e[v][u]-=b;
			}
		};
	//	printf("gg %d %d\n",w01,w02);
		del(pt[0],w01); del(pt[1],w01); ans.pb(VI{lv[0],lv[1],w01});
		del(pt[0],w02); del(pt[2],w02); ans.pb(VI{lv[0],lv[2],w02});
		if (w01%2!=0) del(pt[1],1),del(pt[2],1),ans.pb(VI{lv[1],lv[2],1});
		e[np].erase(lf); e[lf].erase(np); alive[lf]=0;
		if (SZ(e[np])==2) {
			int w=e[np].begin()->se;
		//	printf("zz %d\n",w);
			e[np].clear(); alive[np]=0;
			e[br[1]].erase(np);
			e[br[2]].erase(np);
			e[br[1]][br[2]]=w;
			e[br[2]][br[1]]=w;
		}
	//	puts("ee");
	//	rep(i,1,n+1) for (auto p:e[i]) if (p.fi>i) printf("%d %d %d\n",i,p.fi,p.se);
	//	puts("ff");
	}
	printf("%d\n",SZ(ans));
	for (auto p:ans) printf("%d %d %d\n",p[0],p[1],p[2]);
}