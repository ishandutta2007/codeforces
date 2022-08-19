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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
int n,m,pos[N];
ll t;
int s;
map<ll,int> dp[N];
int go(int s) {
	if (pos[s]!=-1) return pos[s];
	int t=s;
	for (int i=n;i>=1;i--) {
		if (s>=m) s=((s-i)%n+n)%n;
		else s=(s+i)%n;
	}
	return pos[t]=s;
}
int ff(int s,ll n) {
	if (n==0) return s;
	if (n==1) return go(s);
	if (dp[s].count(n)) return dp[s][n];
	else return dp[s][n]=ff(ff(s,n/2),n-n/2);
}
int main() {
	scanf("%d%d",&n,&m);
	scanf("%d%lld",&s,&t);
	s-=1;
	while (t%n!=0) {
		if (s>=m) s=((s-t)%n+n)%n;
		else s=(s+t)%n;
		--t;
	}
	rep(i,0,n) pos[i]=-1;
	printf("%d\n",ff(s,t/n)+1);
}