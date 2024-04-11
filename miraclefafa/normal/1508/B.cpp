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

//int p[1010];
//int n=5;

const int N=101000;
int _,n;
ll k;
int p[N],f[N];
int main() {
/*	rep(i,1,n+1) p[i]=i;
	while (1) {
		int as=1;
		rep(i,2,n+1) if (p[i]<p[i-1]-1) as=0;
		if (as) {
			rep(i,1,n+1) printf("%d ",p[i]);
			puts("");
		}
		if (!next_permutation(p+1,p+n+1)) break;
	}*/
	for (scanf("%d",&_);_;_--) {
		scanf("%d%lld",&n,&k);
		if (n<=61&&k>(1ll<<(n-1))) {
			puts("-1");
			continue;
		}
		--k;
		rep(i,0,n-1) if (i<=60) f[i]=(k>>i)&1; else f[i]=0;
		reverse(f,f+n-1);
		f[n-1]=0;
		for (int i=0;i<n;i++) p[i]=i;
		for (int i=0;i<n;i++) if (f[i]==1) {
			int j=i;
			while (f[j]==1) j++;
			reverse(p+i,p+j+1);
			i=j;
		}
		rep(i,0,n) printf("%d%c",p[i]+1," \n"[i==n-1]);
	}
}