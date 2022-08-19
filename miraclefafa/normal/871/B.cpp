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

const int N=5010;
int n,r1[N],r2[N],p[N],b[N],vis[N],ret,x;
VI ans;
int query(int u,int v) {
	printf("? %d %d\n",u,v);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}
bool check() {
	rep(i,0,n) if (p[i]>=n&&b[i]>=n) return 0;
	rep(i,0,n) vis[i]=0;
	rep(i,0,n) {
		if (vis[p[i]]) return 0;
		vis[p[i]]=1;
	}
	rep(i,0,n) vis[i]=0;
	rep(i,0,n) {
		if (vis[b[i]]) return 0;
		vis[b[i]]=1;
	}
	rep(i,0,n) if (p[b[i]]!=i) return 0;
	return 1;
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) r1[i]=query(0,i);
	r2[0]=r1[0];
	rep(i,1,n) r2[i]=query(i,0);
	rep(p0,0,n) {
		p[0]=p0;
		b[0]=r1[0]^p0;
		rep(i,0,n) p[i]=r2[i]^b[0],b[i]=r1[i]^p[0];
		if (check()) {
			ret++;
			ans=VI(p,p+n);
		}
	}
	puts("!");
	printf("%d\n",ret);
	for (auto p:ans) printf("%d ",p);
	puts("");
}