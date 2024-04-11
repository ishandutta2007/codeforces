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

const int N=110,M=55<<10;
int n,dp[M],pre[M],ch[M];
int pn[20][N][55],nxt[N],ww[N];
VI v[N][N];
char s[N];

void solve() {
	scanf("%d",&n);
	rep(i,0,n) rep(j,0,52) v[i][j].clear();
	rep(i,0,n) {
		scanf("%s",s);
		int m=strlen(s);
		rep(j,0,m) {
			int w=s[j]>='a'?s[j]-'a':s[j]-'A'+26;
			ww[j]=w;
			v[i][w].pb(j);
		}
		per(j,0,52) nxt[j]=-2;
		per(j,0,m) {
			rep(k,0,52) pn[i][j+1][k]=nxt[k];
			nxt[ww[j]]=j;
		}
		rep(k,0,52) pn[i][0][k]=nxt[k];
	}
	vector<VI> ret;
	rep(i,0,52) {
		vector<VI> w; w.pb({});
		rep(j,0,n) {
			vector<VI> nw;
			for (auto k:v[j][i]) {
				for (auto p:w) {
					VI q=p; q.pb(k);
					nw.pb(q);
				}
			}
			w=nw;
		}
		for (auto p:w) {
		//	rep(j,0,n) printf("%d ",p[j]); puts("");
			ret.pb(p);
		}
	}
	ret.pb(VI(n,-1));
	sort(all(ret));
	map<VI,int> id;
	rep(i,0,SZ(ret)) id[ret[i]]=i;
	rep(i,0,SZ(ret)) dp[i]=-1e5;
	dp[0]=0;
	int ans=-1,st=-1;
	rep(i,0,SZ(ret)) {
		VI p=ret[i];
		rep(j,0,52) {
			VI q(n,0);
			bool val=1;
			rep(k,0,n) {
				q[k]=pn[k][p[k]+1][j];
				if (q[k]==-2) val=0;
			}
			if (val) {
				//for (auto x:q) printf("%d ",x); puts("");
				//assert(id.count(q));
				int nid=id[q];
				if (dp[i]+1>dp[nid]) dp[nid]=dp[i]+1,pre[nid]=i,ch[nid]=j;
			}
		}
		if (dp[i]>ans) ans=dp[i],st=i;
	}
	printf("%d\n",ans);
	VI o;
	while (st) {
		o.pb(ch[st]); st=pre[st];
	}
	reverse(all(o));
	for (auto x:o) putchar(x<26?x+'a':x-26+'A');
	puts("");
}

int _;
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}