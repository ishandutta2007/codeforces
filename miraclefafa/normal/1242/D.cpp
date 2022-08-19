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

//set<int> sg;
//int p[1010][10];
//int n=5;

ll rowsum(ll row,ll n);
ll hitpos(ll seg,ll n) {
	return rowsum(seg,n)%(n*n+1);
}

ll rowsum(ll row,ll n) { // 0 index
	if (row==0) return n*(n+1)/2;
	ll seg=row/n;
	ll hpos=hitpos(seg,n);
	ll fl=row%n*n+1,fr=(row%n+1)*n;
	if (fl>=hpos) fl++;
	if (fr>=hpos) fr++;
	ll ls=seg*(n*n+1);
	if (fr-fl+1==n) {
		return (ls+fl+ls+fr)*n/2;
	} else {
		return (ls+fl+ls+fr)*(n+1)/2-ls-hpos;
	}
}
ll pos(ll x,ll n) {
	ll seg=(x-1)/(n*n+1);
	ll hpos=hitpos(seg,n);
	if (x%(n*n+1)==hpos) {
		return (seg+1)*(n+1);
	} else {
		ll rem=(x-1)%(n*n+1);
		if (rem>=hpos) rem-=1;
		return seg*n*(n+1)+rem/n*(n+1)+rem%n+1;
	}
}

/*map<ll,int> q;
int cnt;
int main() {
	int z=n*n+1;
	int x=1;
	for (int i=1;i<=100;i++) {
		int s=0;
		rep(j,0,n) {
			while (sg.count(x)) x++;
			printf("% 3d ",x%z);
			sg.insert(x);
			p[i][j]=x;
			q[x]=++cnt;
			//printf("%d ",p[i][j]-p[i-1][j]);
			s+=x;
		}
		sg.insert(s);
		assert(s==rowsum(i-1,n));
		q[s]=++cnt;
//		printf("%d ",s%z);
		printf("%lld\n",rowsum(i-1,n)%z);
	}
	for (int i=1;i<=100;i++) {
		printf("%d %d %lld\n",i,q[i],pos(i,n));
		assert(q[i]==pos(i,n));
//		assert()
	}
}
*/

int _;
ll n,k;
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%lld%lld",&n,&k);
		printf("%lld\n",pos(n,k));
	}
}