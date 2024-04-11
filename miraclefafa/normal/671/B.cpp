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

const int N=501000;
int n,c[N];
ll k,s,v[N];
int main() {
	scanf("%d%lld",&n,&k);
	ll s=0;
	rep(i,1,n+1) scanf("%d",c+i),s+=c[i];
	sort(c+1,c+n+1);
	rep(i,1,n+1) v[i]=s/n;
	rep(i,1,s%n+1) v[i]++;
	reverse(v+1,v+n+1);
	int l=c[1],r=v[1]+1;
	while (l+1<r) {
		int md=(l+r)>>1;
		ll s=0;
		rep(i,1,n+1) s+=max(md,c[i])-c[i];
		if (s<=k) l=md; else r=md;
	}
	int vl=l;
	l=v[n]-1,r=c[n];
	while (l+1<r) {
		int md=(l+r)>>1;
		ll s=0;
		rep(i,1,n+1) s+=c[i]-min(md,c[i]);
		if (s<=k) r=md; else l=md;
	}
	printf("%d\n",r-vl);
}