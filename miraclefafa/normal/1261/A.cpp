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

const int N=2010;
int _,n,k;
char s[N];
vector<PII> v1,v2;

void gao(char *s,vector<PII> & x) {
	x.clear();
	int m=0;
	rep(i,0,n) if (s[i]=='(') x.pb(mp(++m,i+1));
}

int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&k);
		scanf("%s",s);
		gao(s,v1);
		int t=0;
		rep(i,0,k-1) s[t++]='(',s[t++]=')';
		rep(i,0,n/2-k+1) s[t++]='(';
		rep(i,0,n/2-k+1) s[t++]=')';
		gao(s,v2);
		reverse(all(v2));
		for (auto x:v2) v1.pb(x);
		printf("%d\n",SZ(v1));
		for (auto r:v1) printf("%d %d\n",r.fi,r.se);
	}
}