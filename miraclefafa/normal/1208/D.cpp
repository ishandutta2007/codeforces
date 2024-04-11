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

const int N=200010;

int n,a[N];
ll s[N],c[N];
set<int> v;

void modify(int x,int s) {
	for (;x<=n;x+=x&-x) c[x]+=s;
}
int query(ll s) {
	if (s==0) return 0;
	int x=0;
	per(i,0,18) {
		if (x+(1<<i)<=n&&c[x+(1<<i)]<s) {
			x+=(1<<i);
			s-=c[x];
		}
	}
	return x+1;
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%lld",s+i);
	rep(i,1,n+1) modify(i,i),v.insert(i);
	per(i,1,n+1) {
		a[i]=*v.upper_bound(query(s[i]));
		modify(a[i],-a[i]); v.erase(a[i]);
	}
	rep(i,1,n+1) printf("%d ",a[i]); puts("");
}