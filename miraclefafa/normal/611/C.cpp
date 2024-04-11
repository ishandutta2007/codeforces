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

const int N=510;
int n,m,v1[N][N],v2[N][N];
char s[N][N];
int r1,r2,c1,c2,q;
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) scanf("%s",s[i]+1);
	rep(i,1,n+1) rep(j,1,m) if (s[i][j]=='.'&&s[i][j+1]=='.') v1[i][j]=1;
	rep(i,1,n) rep(j,1,m+1) if (s[i][j]=='.'&&s[i+1][j]=='.') v2[i][j]=1;
	rep(i,1,n+1) rep(j,1,m) v1[i][j]+=v1[i][j-1];
	rep(i,1,n+1) rep(j,1,m) v1[i][j]+=v1[i-1][j];
	rep(i,1,n) rep(j,1,m+1) v2[i][j]+=v2[i][j-1];
	rep(i,1,n) rep(j,1,m+1) v2[i][j]+=v2[i-1][j];
	scanf("%d",&q);
	rep(i,0,q) {
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		printf("%d\n",v1[r2][c2-1]-v1[r1-1][c2-1]-v1[r2][c1-1]+v1[r1-1][c1-1]+
			v2[r2-1][c2]-v2[r1-1][c2]-v2[r2-1][c1-1]+v2[r1-1][c1-1]);
	}
}