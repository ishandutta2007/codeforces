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

const int N=501000;
int n,p,l[N],r[N],k,t[N];
int ans,v[N];
struct node {
	int l,r,len;
};
bool operator < (const node &a,const node &b) {
	return a.len>b.len;
}
node init(int pl,int pr,int len) {
	r[pl]=pr;l[pr]=pl;v[pr]=len;
	return (node){pl,pr,len};
}
priority_queue<node> h;

inline int getint() {
	int ret=0;bool ok=0,neg=0;
	for(;;) {
		int c=getchar();
		if(c>='0'&&c<='9')ret=(ret<<3)+ret+ret+c-'0',ok=1;
		else if(ok)return neg?-ret:ret;
		else if(c=='-')neg=1;
	}
}

int main() {
	k=getint(); n=getint();
	rep(i,0,n) t[i]=getint();
	sort(t,t+n);
	h.push(init(0,1,(1<<30)-1));
	rep(i,1,n) h.push(init(i,i+1,t[i]-t[i-1]));
	h.push(init(n,n+1,(1<<30)-1));
	for (int i=0;i<k;i++) {
		while (1) {
			auto X=h.top(); h.pop();
			if (l[X.r]!=X.l || r[X.l]!=X.r) continue;
			ans+=X.len;
			h.push(init(l[X.l],r[X.r],v[X.l]+v[r[X.r]]-v[X.r]));
			break;
		}
	}
	printf("%d\n",ans);
}