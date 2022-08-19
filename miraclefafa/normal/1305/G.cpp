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
struct dsu {
	static const int N=301000;
	int f[N];
	void init(int n) { rep(i,1,n+1) f[i]=i; }
	int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
	bool merge(int u,int v) {
		u=find(u); v=find(v);
		if (u==v) return 0;
		f[u]=v;
		return 1;
	}
}f;
int n,cnt[N];

int main() {
	scanf("%d",&n);
	ll ans=0;
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		cnt[x]++;
		ans-=x;
	}
	cnt[0]+=1;
	f.init((1<<18));
	per(s,1,(1<<18)) {
		int ns=s;
		while (1) {
			int u=ns,v=(s-ns);
			if (u<v) break;
			if (cnt[u]&&cnt[v]) {
				if (f.merge(u+1,v+1)) {
					ans+=(ll)s*(cnt[u]+cnt[v]-1);
					cnt[u]=cnt[v]=1;
				}
			}
			ns=(ns-1)&s;
		}
	}
	printf("%lld\n",ans);
}