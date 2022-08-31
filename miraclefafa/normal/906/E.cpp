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

const int N=1001000,inf=1<<30;
PII dp[N],pd[N];
int n;
char s[N],p[N],q[N];
struct seg {
	int a,k,sz;
};
vector<seg> G;
void upd(PII &a,PII b) { a.fi=min(a.fi,b.fi); a.se=min(a.se,b.se);}
int main() {
	scanf("%s",p+1);
	scanf("%s",q+1);
	int m=strlen(p+1);
	rep(i,1,2*m+1) if (i%2==1) s[i]=p[i/2+1]; else s[i]=q[i/2];
	n=2*m;
	dp[0]=mp(0,0);
	rep(j,1,n+1) {
		vector<seg> G1,G2;
		for (auto p:G) {
			if (p.a>1&&s[p.a-1]==s[j]) G1.pb((seg){p.a-1,p.k,p.sz});
		}
		int r=-j;
		for (auto p:G1) {
			if (p.a-r!=p.k) {
				G2.pb((seg){p.a,p.a-r,1});
				if (p.sz>1) G2.pb((seg){p.a+p.k,p.k,p.sz-1});
			} else G2.pb(p);
			r=p.a+(p.sz-1)*p.k;
		}
		if(j>1&&s[j-1]==s[j]) G2.pb((seg){j-1,j-1-r,1}),r=j-1;
		G2.pb((seg){j,j-r,1});
		G.clear();
		seg ss=G2[0]; G2.erase(G2.begin());
		for (auto p:G2) {
			if (p.k==ss.k) ss.sz+=p.sz;
			else G.pb(ss),ss=p;
		}
		G.pb(ss);
		bool val=1;
		dp[j]=mp(inf,0);
		if (j%2==1) val=0;
		if (s[j]==s[j-1]) dp[j]=mp(dp[j-2].fi,j-2);
		for (auto p:G) {
			r=p.a+(p.sz-1)*p.k;
			PII c=mp(dp[r-1].fi+1,r-1);
			if (p.sz>1) c=min(c,pd[p.a-p.k]);
			if (p.k<=p.a) pd[p.a-p.k]=c;
			if (val) dp[j]=min(dp[j],c);
		}
	}
	if (dp[n].fi>m) puts("-1");
	else {
		printf("%d\n",dp[n].fi);
		int u=n;
		while (u) {
			int v=dp[u].se;
			if (v<u-2) {
				printf("%d %d\n",v/2+1,u/2);
			}
			u=v;
		}
	}
}