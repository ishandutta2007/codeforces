#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=210;
char s[N][N],brd[N][N];
int n,cov[N][N];
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%s",s[i]);
	rep(i,0,2*n-1) rep(j,0,2*n-1) brd[i][j]='.';
	rep(dx,-(n-1),n) rep(dy,-(n-1),n) {
		bool val=1;
		rep(i,0,n) rep(j,0,n) if (s[i][j]=='o') {
			if (!(i+dx>=n||i+dx<0||j+dy>=n||j+dy<0)&&s[i+dx][j+dy]=='.') val=0;
		}
		if (val) {
			brd[dx+n-1][dy+n-1]='x';
			rep(i,0,n) rep(j,0,n) if (s[i][j]=='o') {
				if (!(i+dx>=n||i+dx<0||j+dy>=n||j+dy<0)) 
					cov[i+dx][j+dy]=1;
			}
		}
	}
	rep(i,0,n) rep(j,0,n) if (s[i][j]=='x'&&!cov[i][j]) {
		puts("NO");
		return 0;
	}
	puts("YES");
	brd[n-1][n-1]='o';
	rep(i,0,2*n-1) puts(brd[i]);
}