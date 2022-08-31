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

map<PII,int> hs;
int m,a,b,c;
PII p[201000];

inline int getint() {
	int ret=0;bool ok=0,neg=0;
	for(;;) {
		int c=getchar();
		if(c>='0'&&c<='9')ret=(ret<<3)+ret+ret+c-'0',ok=1;
		else if(ok)return neg?-ret:ret;
		else if(c=='-')neg=1;
	}
}

int main() {
	m=getint();
	rep(i,0,m) {
		a=getint(); b=getint(); c=getint();
		a+=b;
		int d=gcd(a,c);
		a/=d; c/=d;
		p[i]=mp(a,c);
		hs[p[i]]++;
	}
	rep(i,0,m) printf("%d ",hs[p[i]]);
	puts("");
}