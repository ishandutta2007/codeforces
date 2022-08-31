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

string ss="RGYB";
const int N=510,M=301000;
int n,m,q,cnt[6][N][N],ans[M];
int r1[M],c1[M],r2[M],c2[M];
char s[N];
int main() {
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,n+1) {
		scanf("%s",s+1);
		rep(j,1,m+1) {
			rep(k,0,4) if (ss[k]==s[j]) cnt[k][i][j]=1;
		}
	}
	rep(k,0,4) {
		rep(i,1,n+1) rep(j,1,m+1) cnt[k][i][j]+=cnt[k][i-1][j];
		rep(i,1,n+1) rep(j,1,m+1) cnt[k][i][j]+=cnt[k][i][j-1];
	}
	rep(i,0,q) scanf("%d%d%d%d",r1+i,c1+i,r2+i,c2+i);
	auto query=[&](int k,int r1,int c1,int r2,int c2) {
		return cnt[k][r2][c2]-cnt[k][r1-1][c2]-cnt[k][r2][c1-1]+cnt[k][r1-1][c1-1];
	};
	rep(l,1,251) {
		if (n<2*l||m<2*l) break;
		for (int x=1;x<=n+1-2*l;x++) for (int y=1;y<=m+1-2*l;y++) cnt[4][x][y]=0;
		for (int x=l;x<=n-l;x++) for (int y=l;y<=m-l;y++) {
			if (query(0,x-l+1,y-l+1,x,y)==l*l&&query(1,x-l+1,y+1,x,y+l)==l*l&&
				query(2,x+1,y-l+1,x+l,y)==l*l&&query(3,x+1,y+1,x+l,y+l)==l*l) {
				//printf("%d %d %d\n",l,x-l+1,y-l+1);
				cnt[4][x-l+1][y-l+1]=1;
			}
		}
		for (int x=1;x<=n+1-2*l;x++) for (int y=1;y<=m+1-2*l;y++) cnt[4][x][y]+=cnt[4][x-1][y];
		for (int x=1;x<=n+1-2*l;x++) for (int y=1;y<=m+1-2*l;y++) cnt[4][x][y]+=cnt[4][x][y-1];
		rep(i,0,q) {
			if (r2[i]-r1[i]+1>=2*l&&c2[i]-c1[i]+1>=2*l&&
				query(4,r1[i],c1[i],r2[i]-2*l+1,c2[i]-2*l+1)) ans[i]=l;
		}
	}
	rep(i,0,q) printf("%d\n",4*ans[i]*ans[i]);
}