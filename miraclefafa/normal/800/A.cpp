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
int n,p,a[N],b[N];
int main() {
	scanf("%d%d",&n,&p);
	rep(i,0,n) scanf("%d%d",a+i,b+i);
	ll s=0;
	rep(i,0,n) s+=a[i];
	if (p>=s) {
		puts("-1");
		return 0;
	}
	double l=0,r=1e16;
	rep(it,0,150) {
		double md=(l+r)*0.5;
		double s=0;
		rep(i,0,n) {
			if (b[i]-md*a[i]<0) s+=(md*a[i]-b[i])/p;
		}
		if (s<md) l=md; else r=md;
	}
	printf("%.10f\n",0.5*(l+r));
}