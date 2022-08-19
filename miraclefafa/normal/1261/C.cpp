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

vector<VI> grid,mark,sm;
int n,m;
char s[1010000];

bool check(int fl,int fr,int gl,int gr) {
	if (fl<=0||fr>n||gl<=0||gr>m) return 0;
	return sm[fr][gr]-sm[fl-1][gr]-sm[fr][gl-1]+sm[fl-1][gl-1]==(fr-fl+1)*(gr-gl+1);
}
bool gao(int md) {
	mark=vector<VI>(n+1,VI(m+1,0));
	vector<VI> ff(n+2,VI(m+2,0));
	rep(i,1,n+1) rep(j,1,m+1) {
		if (check(i-md,i+md,j-md,j+md)) {
			ff[i-md][j-md]+=1;
			ff[i+md+1][j-md]-=1;
			ff[i-md][j+md+1]-=1;
			ff[i+md+1][j+md+1]+=1;
			mark[i][j]=1;
		}
	}
	rep(i,1,n+1) rep(j,1,m+1) ff[i][j]+=ff[i][j-1];
	rep(i,1,n+1) rep(j,1,m+1) ff[i][j]+=ff[i-1][j];
	rep(i,1,n+1) rep(j,1,m+1) if ((ff[i][j]>0)!=grid[i][j]) {
		return 0;
	}
	return 1;
}

int main() {
	scanf("%d%d",&n,&m);
	grid=vector<VI>(n+1,VI(m+1,0));
	sm=vector<VI>(n+1,VI(m+1,0));
	rep(i,1,n+1) {
		scanf("%s",s);
		rep(j,1,m+1) {
			sm[i][j]=grid[i][j]=(s[j-1]=='X');
		}
	}
	rep(i,1,n+1) rep(j,1,m+1) sm[i][j]+=sm[i][j-1];
	rep(i,1,n+1) rep(j,1,m+1) sm[i][j]+=sm[i-1][j];
	int l=0,r=600;
	while (l+1<r) {
		int md=(l+r)>>1;
		if (gao(md)) l=md; else r=md;
	}
	gao(l);
	printf("%d\n",l);
	rep(i,1,n+1) {
		rep(j,1,m+1) if (mark[i][j]) putchar('X'); else putchar('.');
		puts("");
	}
}