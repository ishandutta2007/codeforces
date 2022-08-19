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
int n,a[N],val[N],pos[N];
ll ret,s;
map<int,int> hs;

void add(int l,int r) {
//	rep(i,l,r+1) val[i]=max(val[i],r);
	if (l>r) return;
//	printf("Add %d %d\n",l,r);
	auto p=hs.upper_bound(l);
	--p;
	if (p->se>=r) return;
	int prx=l,pry=p->se;
	hs[l]=r;
	while (1) {
		auto p=hs.upper_bound(l);
		s-=(ll)pry*(p->fi-prx);
		prx=p->fi; pry=p->se;
		if (pry>r) {
			s+=(ll)(prx-l)*r;
			break;
		}
		hs.erase(p);
	}
//	printf("%lld\n",s);
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i),pos[a[i]]=i; hs[0]=0;
	rep(i,1,n+1) hs[i]=i-1; hs[n+1]=n+1;
	rep(i,1,n+1) val[i]=i-1;
	s=n*(n-1)/2;
	per(i,1,200001) {
		VI v;
		for (int j=i;j<=200000;j+=i) if (pos[j]) v.pb(pos[j]);
		sort(all(v));
		if (SZ(v)>1) {
			int m=SZ(v);
			add(1,v[m-2]-1);
			add(v[0]+1,v[m-1]-1);
			add(v[1]+1,n);
//			printf("vv %d\n",i);
//			for (auto v:hs) printf("%d %d\n",v.fi,v.se);
//			rep(j,1,n+1) printf("%d ",val[j]); puts("");
		}
		ret+=s-n*(n-1)/2;
//		ll ss=0;
//		rep(j,1,n+1) ss+=val[j];
//		assert(ss==s);
//		printf("= = %d %lld\n",i,s-n*(n-1)/2);
	}
	printf("%lld\n",ret);
}