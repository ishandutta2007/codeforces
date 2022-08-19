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

const int N=101000;
int n,m,u,v,q[N],mark[N],T,ans;
VI e[N];
set<int> st;

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) st.insert(i);
	for (int i=0;i<m;i++) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	rep(i,1,n+1) if (st.count(i)) {
		int t=0;
		st.erase(i); q[t++]=i;
		//printf("ggg %d\n",i);
		rep(j,0,t) {
			int u=q[j];
		//	printf("gg %d\n",u);
			++T;
			for (auto v:e[u]) mark[v]=T;
			VI adj;
			for (auto v:st) if (mark[v]!=T) {
				adj.pb(v);
			}
			for (auto z:adj) q[t++]=z,st.erase(z);
		}
		ans+=1;
	}
	printf("%d\n",ans-1);
}