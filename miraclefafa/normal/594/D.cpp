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

const int M=1000000,N=1501000;
ll ff[N],gg[N],s[N],invs[N],c[N];
int n,m,ql,qr,q,pre[N],r[N],ret[N],a[N];
vector<PII> que[N];
VI d[N];

ll query(int x) { ll s=1; for (;x;x-=x&-x) s=s*c[x]%mod; return s;}
void modify(int x,ll s) { for (;x<=m;x+=x&-x) c[x]=c[x]*s%mod;}
int main() {
	for (int i=2;i<=M;i++) if (!SZ(d[i])) {
		ff[i]=(i-1)*powmod(i,mod-2)%mod; gg[i]=powmod(ff[i],mod-2);
		for (int j=i;j<=M;j+=i) d[j].pb(i);
	}
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i),m+=SZ(d[a[i]]);
	rep(i,1,m+1) c[i]=1;
	s[0]=invs[0]=1;
	rep(i,1,n+1) s[i]=s[i-1]*a[i]%mod,invs[i]=powmod(s[i],mod-2);
	scanf("%d",&q);
	rep(i,0,q) {
		scanf("%d%d",&ql,&qr);
		que[qr].pb(mp(ql,i));
	}
	r[1]=0; int cnt=1;
	rep(i,1,n+1) {
		for (auto v:d[a[i]]) {
			modify(pre[v]+1,ff[v]);
			modify(cnt+1,gg[v]);
			pre[v]=cnt++;
		}
		r[i]=cnt-1;
		for (auto p:que[i]) {
			int l=p.fi;
	//		printf("%lld\n",s[i]*invs[l-1]%mod);
			ret[p.se]=s[i]*invs[l-1]%mod*query(r[l-1]+1)%mod;
		}
	}
	rep(i,0,q) printf("%d\n",ret[i]);
}