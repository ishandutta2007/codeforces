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

const int N=10100;
int n,c,d,cc[N],on[N];
int main() {
	scanf("%d",&n);
	for (int k=2;k<=n;k++) {
		int pos=n/k*(k-1)+max(0,(n%k)-1)-(k-1);
		if (pos>c) c=pos,d=k;
	}
	if (c==0) {
		puts("0");
		fflush(stdout);
		return 0;
	}
	for (int i=0;i<n;i++) if (i%d!=d-1&&i!=n-1) cc[i]=1;
	while (1) {
		int cnt=0;
		rep(i,0,n) cnt+=on[i];
		if (cnt>=c) break;
		VI a;
		rep(i,0,n) if (!on[i]&&cc[i]) a.pb(i);
		if (SZ(a)>d) a.resize(d);
		printf("%d",SZ(a));
		for (auto x:a) printf(" %d",x+1),on[x]=1; puts(""); fflush(stdout);
		int z;
		scanf("%d",&z);
		rep(i,0,SZ(a)) on[(z-1+i)%n]=0;
	}
	puts("0"); fflush(stdout);
}