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

const int N=1010000;
int stk[N],top,a[N],l[N],r[N],n,w,k;
ll s[N];
void dfs(int u,int fl,int fr) {
	int pl=u,pr=w-k+u;
	pl=max(pl,fl); pr=min(pr,fr);
	if (pl<=pr) {
//		printf("ff %d %d %d\n",a[u],pl,pr);
		s[pl]+=a[u],s[pr+1]-=a[u];
	}
	if (l[u]) dfs(l[u],fl,pl-1);
	if (r[u]) dfs(r[u],pr+1,fr);
}
void build(int n) {
	int top=0;
	rep(i,1,n+1) l[i]=r[i]=0;
	rep(i,1,n+1) {
		int k=top;
		while (k>0&&a[stk[k-1]]<a[i]) --k;
		if (k) r[stk[k-1]]=i;
		if (k<top) l[i]=stk[k];
		stk[k++]=i;
		top=k;
	}
	dfs(stk[0],1,w);
	// rt is stk[0]
}

int main() {
	scanf("%d%d",&n,&w); w+=2;
	rep(i,0,n) {
		scanf("%d",&k);
		rep(j,2,k+2) scanf("%d",a+j); a[k+2]=0; k+=2;
		build(k);
	}
	rep(i,2,w) {
		s[i]+=s[i-1];
		printf("%lld ",s[i]);
	}
	puts("");
}