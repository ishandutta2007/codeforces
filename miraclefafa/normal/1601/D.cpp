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

const int N=1010000;
int n,d,s[N],a[N],lg,dp[N],t,c[N];
VI v,vv[N],qr[N];
int query(int x) {
	int s=0;
	for (;x;x-=x&-x) s+=c[x];
	return s;
}

void modify(int x,int s) {
	for (;x<=t;x+=x&-x) c[x]+=s;
}

int main() {
	scanf("%d%d",&n,&d);
	rep(i,0,n) {
		scanf("%d%d",s+i,a+i);
		if (s[i]<d) --i,--n;
		a[i]=max(a[i],d);
		v.pb(s[i]); v.pb(a[i]);
	}
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	t=SZ(v);
	rep(i,0,n) {
		s[i]=lower_bound(all(v),s[i])-v.begin()+1;
		a[i]=lower_bound(all(v),a[i])-v.begin()+1;
		if (s[i]>=a[i]) {
			vv[s[i]].pb(a[i]);
			lg++;
		} else {
			qr[a[i]].pb(i);
		}
	}
	int cnt=0;
	rep(i,1,t+1) {
		// query
		dp[i]=dp[i-1];
		for (auto id:qr[i]) {
			int val=cnt-query(s[id]);
			dp[i]=max(dp[i],1+dp[s[id]]-val);
		}
		for (auto x:vv[i]) {
			modify(x,1),cnt++;
		}
		//printf("%d %d\n",i,dp[i]);
	}
	printf("%d\n",lg+dp[t]);
}