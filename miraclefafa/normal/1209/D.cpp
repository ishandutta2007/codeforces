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
int n,k,f[N],sz[N],se[N];
int u,v;
int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) f[i]=i,sz[i]=1,se[i]=0;
	rep(i,0,k) {
		scanf("%d%d",&u,&v);
		u=find(u); v=find(v);
		if (u==v) se[u]++;
		else {
			f[v]=u;
			sz[u]+=sz[v];
			se[u]+=se[v]+1;
		}
	}
	int ans=0;
	rep(i,1,n+1) if (find(i)==i) {
		ans+=se[i]-sz[i]+1;
	}
	printf("%d\n",ans);
}