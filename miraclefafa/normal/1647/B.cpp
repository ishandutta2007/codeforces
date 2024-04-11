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

const int N=110;
int _,n,m;
char s[N][N];
int g[N][N];
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&m);
		rep(i,0,n) {
			scanf("%s",s[i]);
			rep(j,0,m) g[i][j]=s[i][j]-'0';
		}
		bool isrec=1;
		rep(i,0,n-1) rep(j,0,m-1) {
			int cnt=g[i][j]+g[i][j+1]+g[i+1][j]+g[i+1][j+1];
			if (cnt==3) isrec=0;
		}
		puts(isrec?"YES":"NO");
	}

}