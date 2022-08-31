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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int n,m,q,bd[110][110],r,s,ty;
PII p[110][110];
int main() {
	scanf("%d%d",&n,&m);
	scanf("%d",&q);
	rep(i,0,n) rep(j,0,m) p[i][j]=mp(i,j);
	rep(i,0,q) {
		scanf("%d",&ty);
		if (ty==1) {
			scanf("%d",&r); --r;
			PII q=p[r][0];
			rep(j,0,m-1) p[r][j]=p[r][j+1];
			p[r][m-1]=q;
		} else if (ty==2) {
			scanf("%d",&r); --r;
			PII q=p[0][r];
			rep(j,0,n-1) p[j][r]=p[j+1][r];
			p[n-1][r]=q;
		} else {
			scanf("%d%d",&r,&s); --r; --s;
			scanf("%d",&bd[p[r][s].fi][p[r][s].se]);
		}
	}
	rep(i,0,n) {
		rep(j,0,m) printf("%d ",bd[i][j]);
		puts("");
	}
}