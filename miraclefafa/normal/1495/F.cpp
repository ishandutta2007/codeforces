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
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
int n,q,p[N],a[N],b[N],par[N][20];
ll dep[N],wt[N],d[N],ans,ch[N];
set<int> ts;
stack<int> st;
ll query(int u,int v) {
	ll ans=0;
	per(j,0,19) if (par[v][j]>=u) {
		ans+=dep[v]-dep[par[v][j]];
		v=par[v][j];
	}
	ans+=d[u]-d[v];
	return ans;
}
int main() {
	scanf("%d%d",&n,&q);
	rep(i,1,n+1) scanf("%d",p+i);
	p[n+1]=n+1;
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,1,n+1) scanf("%d",b+i);
	st.push(n+1);
	p[0]=n+2;
	per(i,0,n+1) {
		while (!st.empty()&&p[st.top()]<p[i]) {
			int u=st.top();
			par[u][0]=i;
			wt[u]=a[i]+d[i+1]-d[u];
			st.pop();
		}
		if (!st.empty()) d[i]=min(a[i]+d[i+1],b[i]+d[st.top()]);
		st.push(i);
	}
	rep(i,1,n+1) dep[i]=dep[par[i][0]]+wt[i];
	/*rep(i,1,n+2) {
		printf("%d d[i]: %lld par[i]: %d dep[i]: %lld\n",i,d[i],par[i][0],dep[i]);
	}*/
	rep(j,1,19) rep(i,1,n+2) {
		par[i][j]=par[par[i][j-1]][j-1];
	}
	ts.insert(1); ts.insert(n+1);
	ch[1]=query(1,n+1);
	ans=ch[1];
	rep(i,0,q) {
		int x=1;
		scanf("%d",&x);
		if (x==1) {
			printf("%lld\n",ans);
			continue;
		} else if (ts.count(x)) {
			ans-=ch[x];
			auto it=ts.lower_bound(x);
			auto nit=it; --it; ++nit;
			ans-=ch[*it];
			ch[*it]=query(*it,*nit);
			ans+=ch[*it];
			ts.erase(x);
		} else {
			auto it=ts.lower_bound(x);
			auto pit=it; --pit;
			ans-=ch[*pit];
			ch[*pit]=query(*pit,x);
			ch[x]=query(x,*it);
			ans+=ch[*pit]+ch[x];
			ts.insert(x);
		}
		printf("%lld\n",ans);
	}
}