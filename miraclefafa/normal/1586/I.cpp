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
int n,x[N];
char s[N][N];
PII a[N][N];
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%s",s[i]);
	}
	if (n%2!=0) {
		puts("NONE");
		return 0;
	}
	rep(i,0,n) {
		a[0][i]=mp(i/2,0);
	}
	rep(i,0,n) {
		a[1][0]=a[0][1];
		a[1][n-1]=a[0][n-2];
		rep(j,1,n-1) {
			if (j%2==0) a[1][j]=mp(a[0][j-1].fi,1);
			else a[1][j]=mp(a[0][j+1].fi,1);
		}
	}
	rep(i,2,n) {
		a[i][0]=a[0][i];
		a[i][n-1]=a[0][n-1-i];
		rep(j,1,n-1) {
			a[i][j]=mp(a[i-2][j].fi^a[i-1][j-1].fi^a[i-1][j+1].fi,a[i-2][j].se^a[i-1][j-1].se^a[i-1][j+1].se);
		}
	}
	rep(i,0,n/2) x[i]=-1;
	rep(i,0,n) rep(j,0,n) {
		if (s[i][j]!='.') {
			int id=a[i][j].fi,v=a[i][j].se^(s[i][j]=='S');
			if (x[id]!=-1&&x[id]!=v) {
				puts("NONE");
				return 0;
			}
			x[id]=v;
		}
	}
	rep(i,0,n/2) if (x[i]==-1) {
		puts("MULTIPLE");
		return 0;
	}
	puts("UNIQUE");
	rep(i,0,n) {
		rep(j,0,n) s[i][j]="GS"[x[a[i][j].fi]^a[i][j].se];
		puts(s[i]);
	}
}