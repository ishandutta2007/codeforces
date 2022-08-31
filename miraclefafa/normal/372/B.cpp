#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
//#include <iostream>
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
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
const ll mod=1000000007;
const double eps=1e-9;
const double pi=acos(0)*2;
ll powmod(ll a,ll b) {ll res=1;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const int N=50;
int n,m,q,brd[N][N],sum[N][N],valid[N][N][N][N];
int _a,_b,_c,_d;
char st[N][N];
int main() {
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,n+1) scanf("%s",st[i]);
	rep(i,1,n+1) rep(j,1,m+1) brd[i][j]=st[i][j-1]-'0';
	rep(i,1,n+1) rep(j,1,m+1) sum[i][j]=brd[i][j]==0;
	rep(i,1,n+1) rep(j,1,m+1) sum[i][j]+=sum[i][j-1];
	rep(i,1,n+1) rep(j,1,m+1) sum[i][j]+=sum[i-1][j];
	rep(a,1,n+1) rep(c,a,n+1) rep(b,1,m+1) rep(d,b,m+1) {
		valid[a][c][b][d]=(sum[c][d]-sum[a-1][d]-sum[c][b-1]+sum[a-1][b-1]==(d-b+1)*(c-a+1));
	}
	rep(a,1,n+1) rep(c,1,n+1) rep(b,1,m+1) rep(d,1,m+1) valid[a][c][b][d]+=valid[a-1][c][b][d];
	rep(a,1,n+1) rep(c,1,n+1) rep(b,1,m+1) rep(d,1,m+1) valid[a][c][b][d]+=valid[a][c-1][b][d];
	rep(a,1,n+1) rep(c,1,n+1) rep(b,1,m+1) rep(d,1,m+1) valid[a][c][b][d]+=valid[a][c][b-1][d];
	rep(a,1,n+1) rep(c,1,n+1) rep(b,1,m+1) rep(d,1,m+1) valid[a][c][b][d]+=valid[a][c][b][d-1];
	rep(i,0,q) {
		scanf("%d%d%d%d",&_a,&_b,&_c,&_d);
		printf("%d\n",valid[_c][_c][_d][_d]-valid[_a-1][_c][_d][_d]-valid[_c][_c][_b-1][_d]+valid[_a-1][_c][_b-1][_d]);
	}
	return 0;
}