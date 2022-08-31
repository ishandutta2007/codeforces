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

const int N=401000;
int n;
ll c,v[N],s[N];
ll nd[4*N];
void upd(int p) {
	nd[p]=max(nd[p+p],nd[p+p+1]);
}
ll query(int p,int l,int r,int tl,int tr) {
	if (tl==l&&tr==r) return nd[p];
	else {
		int md=(l+r)>>1;
		if (tr<=md) return query(p+p,l,md,tl,tr);
		else if (tl>md) return query(p+p+1,md+1,r,tl,tr);
		else return max(query(p+p,l,md,tl,md),query(p+p+1,md+1,r,md+1,tr));
	}
}
void modify(int p,int l,int r,int x,ll v) {
	if (l==r) nd[p]=v;
	else {
		int md=(l+r)>>1;
		if (x<=md) modify(p+p,l,md,x,v);
		else modify(p+p+1,md+1,r,x,v);
		upd(p);
	}
}
int main() {
	scanf("%d%lld",&n,&c);
	rep(i,1,2*n) scanf("%lld",v+i),v[i]+=v[i-1];
	int r=0;
	rep(i,1,n+1) {
		while (r<i&&v[2*i-1]-v[2*r]>c) ++r;
		// r -> i-1 s[i]=s[j]+v[2*i-1]-v[2*j]
		if (r>0) s[i]=s[r-1]+c;
		if (r<=i-1) s[i]=max(s[i],v[2*i-1]+query(1,0,n,r,i-1));
		modify(1,0,n,i,s[i]-v[2*i]);

	}
	printf("%lld\n",s[n]);
}