#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
// head

#define y1 asfsafdsafd
int b[1010][1010][10][10];
int lg[1010];
int x1,y1,x2,y2,_,x,n,m;
int query(int x1,int x2,int y1,int y2) {
	int p1=lg[x2-x1+1],p2=lg[y2-y1+1];
	return max(max(b[x1][y1][p1][p2],b[x2+1-(1<<p1)][y1][p1][p2]),
		max(b[x1][y2+1-(1<<p2)][p1][p2],b[x2+1-(1<<p1)][y2+1-(1<<p2)][p1][p2]));
}
inline int getint() {
	int ret=0;bool ok=0;
	for(;;) {
		int c=getchar();
		if(c>='0'&&c<='9')ret=(ret<<3)+ret+ret+c-'0',ok=1;
		else if(ok)return ret;
	}
}

int main() {
	n=getint(); m=getint();
	rep(i,1,n+1) rep(j,1,m+1) {
		x=getint();
		if (x==1) b[i][j][0][0]=min(b[i-1][j-1][0][0],min(b[i][j-1][0][0],b[i-1][j][0][0]))+1;
	}
	rep(k2,1,10) rep(i,1,n+1) rep(j,1,m+1) {
		b[i][j][0][k2]=b[i][j][0][k2-1];
		if (j+(1<<(k2-1))<=m) b[i][j][0][k2]=max(b[i][j][0][k2],b[i][j+(1<<(k2-1))][0][k2-1]);
	}
	rep(k1,1,10) rep(k2,0,10) rep(i,1,n+1) rep(j,1,m+1) {
		b[i][j][k1][k2]=b[i][j][k1-1][k2];
		if (i+(1<<(k1-1))<=n) b[i][j][k1][k2]=max(b[i][j][k1][k2],b[i+(1<<(k1-1))][j][k1-1][k2]);
	}
	rep(i,2,1001) lg[i]=lg[i>>1]+1;
	for (_=getint();_;_--) {
		x1=getint(); y1=getint();
		x2=getint(); y2=getint();
		int l=0,r=min(x2-x1+1,y2-y1+1)+1;
		while (l+1<r) {
			int md=(l+r)>>1;
			if (query(x1+md-1,x2,y1+md-1,y2)>=md) l=md; else r=md;
		}
		printf("%d\n",l);
	}
}
// test