#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=201000;
int n,a[N],b[N],c[N],d[N],e[N],dis[N],vis[N],pre[N],q[N],m;
VI vx,vy,dd;
set<PII> cc[N];
void modify(int x,PII s) {
	for (;x<=m;x+=x&-x) cc[x].insert(s);
}
void query(int x,int v) {
	dd.clear();
	for (;x;x-=x&-x) {
		while (1) {
			auto it=cc[x].lower_bound(mp(v,-1));
			if (it==cc[x].end()) break;
			dd.pb(it->se);
			cc[x].erase(it);
		}
	}
}
void print(int u) {
	printf("%d\n",dis[u]+1);
	for (;u!=-1;u=pre[u]) {
		printf("%d ",u+1);
	}
	puts("");
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d%d%d%d",a+i,b+i,c+i,d+i),vx.pb(a[i]),vx.pb(c[i]),vy.pb(b[i]),vy.pb(d[i]);
	sort(all(vx)); sort(all(vy));
	if (vx[0]!=0||vy[0]!=0) {
		puts("-1");
		return 0;
	}
	rep(i,0,n) vis[i]=0;
	vis[n-1]=1; q[0]=n-1; pre[n-1]=-1;
	m=SZ(vx);
	rep(i,0,n) {
		e[i]=m-(lower_bound(vx.begin(),vx.end(),a[i])-vx.begin());
		c[i]=m-(lower_bound(vx.begin(),vx.end(),c[i])-vx.begin());
		modify(c[i],mp(d[i],i));
	}
	int t=1;
	rep(i,0,t) {
		int u=q[i];
		if (a[u]==0&&b[u]==0) {
			print(u);
			return 0;
		}
		query(e[u],b[u]);
		for (auto v:dd) {
			if (vis[v]) continue;
			dis[v]=dis[u]+1; vis[v]=1;
			pre[v]=u; q[t++]=v;
		}
	}
	puts("-1");
}