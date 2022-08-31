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

int n,p;
int main() {
	scanf("%d%d",&n,&p);
	int ans=101;
	for (int i=1;i<=100;i++) {
		int s=n-p*i;
		if (s<=0) continue;
		int c=__builtin_popcount(s);
		if (i>=c&&i<=s) ans=min(ans,i);
	}
	if (ans==101) ans=-1;
	printf("%d\n",ans);
}