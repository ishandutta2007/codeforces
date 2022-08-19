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

const int N=2050;
bitset<2048> f[N],mask[N];
int pc[N],n,m,q;
set<PII> st,inv;
PII cc[N][N];

int ff(const bitset<2048> &a) {
//	rep(i,0,2048) if (a[i]) return i;
	return a._Find_first();
}

bool check(int a,int b) {
//	printf("gg %d %d\n",a,b);
	if (a==-1||b==-1) return 0;
	bitset<2048> g=f[a]&f[b]; g[2047]=1;

	cc[a][b]=mp(ff(g^f[a]),ff(g^f[b]));
	return (cc[a][b].fi!=2047);
}
void output(int a,int b) {
	PII x(a,cc[a][b].fi+1),y(b,cc[a][b].se+1);
	if (x>y) swap(x,y);
	if (x.se>y.se) swap(x.se,y.se);
/*	assert(x.fi<y.fi); assert(1<=x.fi&&y.fi<=n);
	assert(x.se<y.se); assert(1<=x.se&&y.se<=m);
	assert(f[x.fi][x.se-1]==f[y.fi][y.se-1]&&f[x.fi][x.se-1]!=f[y.fi][x.se-1]&&
		f[x.fi][x.se-1]!=f[x.fi][y.se-1]);
	puts("1");*/
	printf("%d %d %d %d\n",x.fi,x.se,y.fi,y.se);
}

int main() {
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,m+1) {
		mask[i]=mask[i-1];
		mask[i][i-1]=1;
	}
	rep(i,1,n+1) st.insert(mp(0,i));
	st.insert(mp(-1,-1));
	st.insert(mp(m+1,-1));	
	rep(i,0,q) {
		int a,l,r;
		scanf("%d%d%d",&a,&l,&r);
		auto it=st.find(mp(pc[a],a));
		auto pit=it,qit=it;
		--pit; ++qit;
		if (inv.count(mp(pit->se,it->se))) {
			inv.erase(mp(pit->se,it->se));
		}
		if (inv.count(mp(it->se,qit->se))) {
			inv.erase(mp(it->se,qit->se));
		}
		if (check(pit->se,qit->se)) inv.insert(mp(pit->se,qit->se));
		st.erase(it);
		f[a]^=mask[r]^mask[l-1];
		pc[a]=f[a].count();
		st.insert(mp(pc[a],a));
		it=st.find(mp(pc[a],a));
		pit=it,qit=it;
		--pit; ++qit;
		if (inv.count(mp(pit->se,qit->se))) {
			inv.erase(mp(pit->se,qit->se));
		}
		if (check(pit->se,it->se)) inv.insert(mp(pit->se,it->se));
		if (check(it->se,qit->se)) inv.insert(mp(it->se,qit->se));
		if (inv.empty()) {
			puts("-1");
		} else {
			auto it=inv.begin();
			output(it->fi,it->se);
		}
	}
}