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
int p[N],f[N],n;
vector<array<int,3>> seq,sq;
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",p+i);
	rep(i,2,n+1) f[i]=p[i]>p[i-1];
	int lg=0;
	for (int l=2;l<=n;l++) {
		int r=l;
		while (r<=n&&f[r]==f[l]) r++;
		seq.pb({r-l,l-1,r-1});
		//printf("%d %d %d\n",r-l+2,l-1,r-1);
		lg=max(lg,r-l);
		l=r-1;
	}
	//int cnt=0;
	for (auto x:seq) if (x[0]==lg) {
		sq.pb(x);
		//cnt++;
	}
	if (SZ(sq)!=2) {
		puts("0");
		return 0;
	}
	int mid=sq[0][2];
	if (sq[0][2]!=sq[1][1]) {
		puts("0");
		return 0;
	}
	if (p[sq[0][2]]<p[sq[0][2]+1]) {
		puts("0");
		return 0;
	}
	if (lg%2==0) {
		puts("1");
	} else puts("0");
}