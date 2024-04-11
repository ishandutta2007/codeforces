#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
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

const int M=501000,N=2010;
int n,m,x[M],y[M];
bitset<N*2> g[N];
void gauss(int n) {
	rep(i,0,n) {
		int p=-1;
		rep(j,i,n) if (g[j][i]) { p=j; break; }
		swap(g[i],g[p]);
		rep(j,i+1,n) if (g[j][i]) g[j]^=g[i];
	}
	per(i,0,n) rep(j,0,i) if (g[j][i]) g[j]^=g[i];
/*	rep(i,0,n) {
		rep(j,0,2*n) printf("%d",g[i][j]==1);
		puts("");
	}*/
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d",x+i,y+i); --x[i]; --y[i];
		g[x[i]][y[i]]=1;
	}
	rep(i,0,n) g[i][n+i]=1;
	gauss(n);
	rep(i,0,m) {
		puts(g[y[i]][x[i]+n]==0?"YES":"NO");
	}
}