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
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int n;

const int AC_SIGMA=14,AC_V=22,AC_N=2010;
struct node {
	node *go[AC_V],*fail,*f;
	ll fg;
}pool[AC_N],*cur,*root,*q[AC_N];
node* newnode() {
	node *p=cur++;
	memset(p->go,0,sizeof(p->go)); p->fail=p->f=NULL; p->fg=0;
	return p;
}
void init() { cur=pool; root=newnode();}
node* append(node *p,int w) {
	if (!p->go[w]) p->go[w]=newnode(),p->go[w]->f=p;
	return p=p->go[w];
}
void build() {
	int t=1;
	q[0]=root;
	rep(i,0,t) rep(j,0,AC_SIGMA) if (q[i]->go[j]) {
		node *v=q[i]->go[j],*p=v->f->fail;
		while (p&&!p->go[j]) p=p->fail;
		if (p) v->fail=p->go[j]; else v->fail=root;
		q[t++]=q[i]->go[j];
	}
	rep(i,0,t) if (q[i]->fail) q[i]->fg+=q[i]->fail->fg;
	rep(i,0,t) rep(j,0,AC_SIGMA) if (!q[i]->go[j]) {
		node *p=q[i]->fail;
		if (!p) q[i]->go[j]=root; else q[i]->go[j]=p->go[j];
	}
}

int k,go[20][1010];
ll val[20][1010];
char s[401000];
ll dp[(1<<14)+10][1010],tmp[1010];

int main() {
	scanf("%d",&k);
	init();
	rep(i,0,k) {
		scanf("%s",s);
		node *p=root;
		int m=strlen(s);
		rep(j,0,m) p=append(p,s[j]-'a');
		int w;
		scanf("%d",&w);
		p->fg+=w;
	}
	build();
	scanf("%s",s);
	int n=strlen(s);
	VI qm;
	rep(i,0,n) if (s[i]=='?') qm.pb(i);
	int m=SZ(qm),g=cur-pool;
	rep(S,0,(1<<14)) rep(j,0,g) dp[S][j]=-(1ll<<60);
	dp[0][0]=0;
	/*rep(j,0,g) {
		printf("%d %lld\n",j,pool[j].fg);
		rep(k,0,14) printf("go %d %d %d\n",j,k,pool[j].go[k]-pool);
	}*/
	ll ans=-(1ll<<60);
	rep(pf,0,m+1) {
		int l=(pf==0)?0:qm[pf-1]+1;
		int r=(pf==m)?(n-1):(qm[pf]-1);
		rep(j,0,g) {
			node *p=pool+j;
			ll ss=0;
			rep(k,l,r+1) {
				assert(s[k]!='?');
				p=p->go[s[k]-'a'];
				ss+=p->fg;
			}
			go[pf][j]=p-pool;
			val[pf][j]=ss;
		}
	}
	rep(S,0,(1<<14)) {
		int pf=__builtin_popcount(S);
		if (pf>m) continue;
		rep(j,0,g) tmp[j]=-(1ll<<60);
		rep(j,0,g) tmp[go[pf][j]]=max(tmp[go[pf][j]],dp[S][j]+val[pf][j]);
		if (__builtin_popcount(S)==m) {
			rep(i,0,g) ans=max(ans,tmp[i]);
		}
		//rep(k,0,g) printf("Tmp %d %d %lld\n",S,k,tmp[k]);
		//rep(k,0,g) printf("Dp %d %d %lld\n",S,k,dp[S][k]);
		rep(j,0,14) if (!(S&(1<<j))) {
			rep(k,0,g) {
				node *p=pool[k].go[j];
				dp[S|(1<<j)][p-pool]=max(dp[S|(1<<j)][p-pool],tmp[k]+p->fg);
			}
		}
	}
	printf("%lld\n",ans);
}