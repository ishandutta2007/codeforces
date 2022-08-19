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
int n,m,u[N],v[N],w[N],f[N],sz[N],se[N],ord[N];
ll ret;
int find(int u) { return f[u]==u?u:f[u]=find(f[u]); }
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) scanf("%d%d%d",u+i,v+i,w+i);
	rep(i,0,m) ord[i]=i;
	sort(ord,ord+m,[&](int p,int q){ return w[p]>w[q]; }); 
	rep(i,1,n+1) f[i]=i,sz[i]=1,se[i]=0;
	rep(i,0,m) {
		int p=u[ord[i]],q=v[ord[i]],r=w[ord[i]];
		if (find(p)==find(q)) {
			int s=f[p];
			if (se[s]<sz[s]) {
				se[s]++;
				ret+=r;
			}
		} else {
			int s=f[p],t=f[q];
			if (se[s]+se[t]<sz[s]+sz[t]) {
				f[s]=t;
				se[t]+=se[s]+1;
				sz[t]+=sz[s];
				ret+=r;
			}
		}
	}
	printf("%lld\n",ret);
}