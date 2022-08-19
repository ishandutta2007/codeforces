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

int n,m,_,r[100],c[100];
char s[100][100];
void solve() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) scanf("%s",s[i]);
	rep(i,0,n) r[i]=0;
	rep(i,0,m) c[i]=0;
	int cA=0;
	rep(i,0,n) rep(j,0,m) if (s[i][j]=='A'){
		cA++;
		r[i]++,c[j]++;
	}
	if (cA==n*m) {
		puts("0");
		return;
	}
	if (cA==0) {
		puts("MORTAL");
		return;
	}
	if (r[0]==m||r[n-1]==m||c[0]==n||c[m-1]==n) {
		puts("1");
		return;
	}
	if (s[0][0]=='A'||s[0][m-1]=='A'||s[n-1][0]=='A'||s[n-1][m-1]=='A') {
		puts("2");
		return;
	}
	rep(i,0,n) if (r[i]==m) { puts("2"); return;}
	rep(i,0,m) if (c[i]==n) { puts("2"); return;}
	if (r[0]||r[n-1]||c[0]||c[m-1]) {
		puts("3");
		return;
	}
	puts("4");
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}