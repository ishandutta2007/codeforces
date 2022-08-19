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

const int N=1010;
int n,p[N][N],vis[N];
long double E[N],prob[N],coef[N];
int main() {
	scanf("%d",&n);
	rep(i,0,n) rep(j,0,n) scanf("%d",&p[i][j]);
	rep(i,0,n) E[i]=1e30,prob[i]=1,coef[i]=0;
	E[n-1]=0;
	rep(k,0,n) {
		long double mv=1e30; int ps=-1;
		rep(i,0,n) if (!vis[i]&&E[i]<mv) mv=E[i],ps=i;
		vis[ps]=1;
		if (ps==0) {
			printf("%.15f\n",(double)E[0]);
			return 0;
		}
		rep(i,0,n) if (!vis[i]) {
			coef[i]+=E[ps]*prob[i]*0.01*p[i][ps];
			prob[i]*=(1-0.01*p[i][ps]);
			if (prob[i]<1-1e-6) E[i]=(1+coef[i])/(1-prob[i]);
		}
	}
	assert(0);
}