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

const int N=1010;
int f[N],c[N],sz[N],p[N];
int n,m,k,u,v;
int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
int main() {
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n+1) f[i]=i;
	rep(i,1,k+1) scanf("%d",c+i);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		f[find(u)]=find(v);
	}
	rep(i,1,n+1) sz[find(i)]++;
	int ts=n;
	rep(i,1,k+1) {
		p[i]=sz[find(c[i])];
		ts-=p[i];
	}
	int v=max_element(p+1,p+k+1)-p,ae=0;
	p[v]+=ts;
	rep(i,1,k+1) ae+=p[i]*(p[i]-1)/2;
	printf("%d\n",ae-m);
}