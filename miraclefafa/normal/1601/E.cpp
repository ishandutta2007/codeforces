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

const int N=301000;
int n,qq,k,a[N],top;
vector<PII> que[N];
array<int,3> s[N];
ll ans[N];

int qquery(int x) {
	int l=0,r=top-1;
	while (l+1<r) {
		int mid=(l+r)>>1;
		if (s[mid][1]<=x) r=mid; else l=mid;
	}
	return s[r][0];
}
struct ds {
	vector<array<ll,4>> s;
	int top;
	void upd(int id) {
		vector<array<ll,4>> blk;
		blk.pb({a[id],id,id,0});
		while (top>0) {
			int val=qquery(s[top-1][1]);
			if (val!=s[top-1][0]) {
				auto z=s[top-1]; z[0]=val;
				blk.pb(z);
				--top;
			} else break;
		}
		reverse(all(blk));
		rep(i,0,SZ(blk)) {
			if (top==0||blk[i][0]!=s[top-1][0]) {
				auto z=blk[i];
				z[3]=top==0?0:s[top-1][3]+((s[top-1][2]-s[top-1][1])/k+1)*s[top-1][0];
				s[top++]=z;
			} else {
				s[top-1][1]=blk[i][1];
			}
		}
	}
	ll query(int val) {
		if (val>s[0][2]) return 0;
		int l=-1,r=top-1;
		while (l+1<r) {
			int mid=(l+r)>>1;
			if (s[mid][1]<=val) r=mid; else l=mid;
		}
		return s[r][3]+((s[r][2]-val)/k+1)*s[r][0];
	}
}q[N];
int main() {
	scanf("%d%d%d",&n,&qq,&k);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,0,qq) {
		int l,r;
		scanf("%d%d",&l,&r),que[l].pb(mp(r,i));
	}
	rep(i,0,k) q[i].s.resize(n/k+5);
	s[top++]={-1,n+1,n+1};
	per(i,1,n+1) {
		while (a[i]<s[top-1][0]) --top;
		s[top]={a[i],i,s[top-1][1]-1}; ++top;
		q[i%k].upd(i);
		for (auto x:que[i]) {
			int rr=(x.fi-i)/k*k+k+i;
			ans[x.se]=q[i%k].query(i)-q[i%k].query(rr);
		}
	}
	rep(i,0,qq) printf("%lld\n",ans[i]);
}