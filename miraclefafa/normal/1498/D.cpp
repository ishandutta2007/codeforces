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

const int N=101000;
int n,m,d[N],way[N],go[N];
int main() {
	scanf("%d%d",&n,&m);
	memset(d,-1,sizeof(d));
	d[0]=0;
	for (int j=1;j<=n;j++) {
		int t,y;
		ll x;
		scanf("%d%lld%d",&t,&x,&y);
		for (int i=0;i<=m;i++) way[i]=(d[i]<0?y+1:0);
		for (int i=0;i<=m;i++) {
			if (t==1) {
				ll w=(i+(x+99999)/100000);
				if (w>m+1) w=m+1;
				go[i]=w;				
			} else {
				ll w=((ll)i*x+99999)/100000;
				if (w>m+1) w=m+1;
				go[i]=w;
			}
			//printf("%d %d %d\n",i,go[i],way[i]);
			way[go[i]]=min(way[go[i]],way[i]+1);
		}
		for (int i=0;i<=m;i++) if (d[i]==-1&&way[i]<=y) {
			d[i]=j;
		}
	}
	rep(i,1,m+1) printf("%d ",d[i]); puts("");
}