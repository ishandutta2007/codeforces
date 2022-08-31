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
int n,x,zz[N],k,pos,ans[N],c[N],m;
vector<PII> ret[N];
PII p[N];

void modify(int x,int s) {
//	printf("mm %d\n",x);
	for (;x<=n;x+=x&-x) c[x]+=s;
}
int query(int s) {
	int z=0;
	per(j,0,20) if (z+(1<<j)<=n&&c[z+(1<<j)]<s) {
		z+=(1<<j);
		s-=c[z];
	}
//	printf("gg %d %d\n",z,s);
	return z;
}

int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",&x),p[i]=mp(-x,i+1),zz[i]=x;
	sort(p,p+n);
	scanf("%d",&m);
	rep(i,0,m) scanf("%d%d",&k,&pos),ret[k].pb(mp(pos,i));
	rep(i,0,n) {
		modify(p[i].se,1);
		for (auto q:ret[i+1]) ans[q.se]=zz[query(q.fi)];
	}
	rep(i,0,m) printf("%d\n",ans[i]);
}