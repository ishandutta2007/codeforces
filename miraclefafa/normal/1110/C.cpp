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

map<int,int> hs;
int q,x;
int main() {
	int a=3;
	while (1) {
		int d=1;
		for (int i=2;i*i<=a;i++) if (a%i==0) {
			d=a/i; break;
		}
		fprintf(stderr,"%d %d\n",a,d);
		hs[a]=d;
		a=a*2+1;
		if (a>(1<<25)) break;
	}
	for (scanf("%d",&q);q;q--) {
		scanf("%d",&x);
		auto it=hs.lower_bound(x);
		if (it->fi==x) {
			printf("%d\n",it->se);
		} else {
			printf("%d\n",it->fi);
		}
	}
}