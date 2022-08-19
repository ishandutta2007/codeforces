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

const int N=101000;
VI e[N];
int d[N],u[N],v[N],n,m,q[N];
bool check(int x) {
	rep(i,1,n+1) e[i].clear(),d[i]=0;
	rep(i,0,x) e[u[i]].pb(v[i]),d[v[i]]++;
	int t=0;
	rep(i,1,n+1) if (d[i]==0) q[t++]=i;
	rep(i,0,t) {
		if (t!=i+1) return 0;
		int u=q[i];
		for (auto v:e[u]) if ((--d[v])==0) q[t++]=v;
	}
	return 1;
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) scanf("%d%d",u+i,v+i);
	if (!check(m)) { puts("-1"); return 0;}
	int l=-1,r=m;
	while (l+1<r) {
		int md=(l+r)>>1;
		if (check(md)) r=md; else l=md;
	}
	printf("%d\n",r);
}