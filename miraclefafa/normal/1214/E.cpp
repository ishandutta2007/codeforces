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

const int N=201000;
int n,pos[N];
PII p[N];
vector<PII> ans;
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&p[i].fi),p[i].se=i;
	sort(p+1,p+n+1); reverse(p+1,p+n+1);
	auto add=[&](int u,int v) {
		ans.pb(mp(u,v));
	};
	rep(i,1,n+1) {
		pos[i]=2*p[i].se-1;
		if (i>1) add(pos[i-1],pos[i]);
	}
	int len=n;
	rep(i,1,n+1) {
		int c=i+p[i].fi;
		if (c==len+1) {
			pos[c]=2*p[i].se;
			add(pos[len],pos[c]);
			len++;
		} else {
			add(pos[c-1],2*p[i].se);
		}
	}
	for (auto p:ans) printf("%d %d\n",p.fi,p.se);
}