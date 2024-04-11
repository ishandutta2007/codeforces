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

const int N=1010000;

int n,a[N],f[N];
int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
bool solve() {
	scanf("%d",&n);
	set<int> s;
	rep(i,1,n+1) {
		scanf("%d",a+i);
		s.insert(a[i]);
	}
	if (SZ(s)<n) return 1;
	rep(i,1,n+1) f[i]=i;
	int cyc=n;
	rep(i,1,n+1) if (find(i)==find(a[i])) --cyc;
	else {
		f[find(i)]=find(a[i]);
	}
	return cyc%2==0;
}

int _;
int main() {
	for (scanf("%d",&_);_;_--) {
		puts(solve()?"YES":"NO");
	}
}