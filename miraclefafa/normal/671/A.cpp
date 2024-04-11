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

const int N=101000;
int n;
PII a,b,t,p[N];
double dis[N],dis1[N],dis2[N],pre[N],suf[N],sm,ret;
double calc(PII a,PII b) {
	double x=a.fi-b.fi,y=a.se-b.se;
	return sqrt(x*x+y*y);
}
int main() {
	scanf("%d%d%d%d%d%d",&a.fi,&a.se,&b.fi,&b.se,&t.fi,&t.se);
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d%d",&p[i].fi,&p[i].se);
	rep(i,1,n+1) {
		dis[i]=calc(t,p[i]);
		sm+=dis[i]*2;
		dis1[i]=calc(a,p[i]);
		dis2[i]=calc(b,p[i]);
	}
	ret=1e30;
	rep(i,1,n+1) ret=min(ret,sm-dis[i]+dis1[i]);
	rep(i,1,n+1) ret=min(ret,sm-dis[i]+dis2[i]);
	pre[0]=1e30;
	rep(i,1,n+1) pre[i]=min(pre[i-1],-dis[i]+dis2[i]);
	suf[n+1]=1e30;
	per(i,1,n+1) suf[i]=min(suf[i+1],-dis[i]+dis2[i]);
	rep(i,1,n+1) ret=min(ret,sm-dis[i]+dis1[i]+min(pre[i-1],suf[i+1]));
	printf("%.10f\n",ret);
	// a go first
}