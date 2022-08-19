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

const int N=201000;
int n,m,r[N],f[N],x,k;
VI d[N];
int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) {
		scanf("%d",r+i); r[i]^=1;
	}
	rep(i,0,2*m) f[i]=i;
	rep(i,0,m) {
		scanf("%d",&x);
		rep(j,0,x) {
			scanf("%d",&k);
			d[k].pb(i);
		}
	}
	rep(i,1,n+1) {
		int u=d[i][0],v=d[i][1];
		f[find(2*u)]=find((2*v)^r[i]);
		f[find(2*u+1)]=find((2*v+1)^r[i]);
	}
	rep(i,0,m) if (find(2*i)==find(2*i+1)) return puts("NO"),0;
	puts("YES");
}