#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <complex>
using namespace std;
#define rep(i,a,n) for (int i=a;i<(int)n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ACCU accumulate
#define TWO(x) (1<<(x))
#define TWOL(x) (1ll<<(x))
#define clr(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (0<=(x)&&(x)<n&&0<=(y)&&(y)<m)
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef complex<double> CD;
const int inf=0x20202020;
const ll mod=1000000007;
const double eps=1e-9;
const double pi=3.1415926535897932384626;
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

const int N=101000;
VI d,e[N];
int n,k,p,u,v;
ll sd[N];
void dfs(int u,int f,int dep) {
	d.pb(dep);
	rep(i,0,SZ(e[u])) {
		int v=e[u][i];
		if (v==f) continue;
		dfs(v,u,dep+1);
	}
}
bool check(ll x) {
	rep(i,1,n+1-x) if (d[i+x-1]*x-(sd[i+x-1]-sd[i-1])<=p) return 1;
	return 0;
}
int main() {
	scanf("%d%d%d",&n,&k,&p);
	rep(i,1,n) scanf("%d%d",&u,&v),e[u].pb(v),e[v].pb(u);
	dfs(1,0,0);
	sort(all(d));
	rep(i,1,n) sd[i]=sd[i-1]+d[i];
	int l=0,r=min(k+1,n);
	while (l+1<r) {
		int md=(l+r)>>1;
		if (check(md)) l=md; else r=md; 
	}
	printf("%d\n",l);
}