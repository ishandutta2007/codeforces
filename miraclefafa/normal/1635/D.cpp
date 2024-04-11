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
set<int> s;
map<int,int> hs;
int n,p,x[N];

bool gen(int x) {
	if (x<=0) return 0;
	if (x%2==1) {
		if (s.count((x-1)/2)) return 1;
		else return gen((x-1)/2);
	} else {
		if (x%4!=0) return 0;
		if (s.count(x/4)) return 1;
		else return gen(x/4);
	}
}

int gao(int p) {
	if (hs.count(p)) {
		return hs[p];
	}
	if (p<=-1) {
		return hs[p]=0;
	} else if (p<=30) {
		ll v=gao(p-1);
		// [2^(p-1), 2^p -1]
		v=(v+gao(p-1)-gao(p-3))%mod;
		rep(i,1,n+1) if (x[i]<(1<<p)&&(p==0||x[i]>=(1<<(p-1)))) {
			if (!gen(x[i])) v=v+1;
		}
		return hs[p]=v%mod;
	} else {
		ll v=gao(p-1);
		// [2^(p-1), 2^p -1]
		v=v+gao(p-1)-gao(p-3);
		return hs[p]=v%mod;
	}
}

int main() {
	scanf("%d%d",&n,&p);
	for (int i=1;i<=n;i++) {
		scanf("%d",x+i);
		s.insert(x[i]);
	}
	int ans=gao(p);
	if (ans<0) ans+=mod;
	printf("%d\n",ans);
	//for (auto x:hs) printf("zz %d %d\n",x.fi,x.se);
}