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

const ll inf=-(1ll<<60);
const int N=101000;
int n,a[N],b[N],c[N];
ll profit[N],pp[N];
ll gg() {
	ll s=0,cnt=0,ss=0;
	rep(i,0,n) if (a[i]>=0) c[i]=1;
	per(i,0,n) {
		if (ss+(ll)(i+1)*a[i]>=0) c[i]=1;
		ss+=a[i];
	}
	ss=0;
	rep(i,0,n) if (c[i]) s+=(++cnt)*a[i];
	++cnt;
	per(i,0,n) {
		if (!c[i]) pp[i]=cnt*a[i]+ss;
		else ss+=a[i],--cnt;
	}
	int m=0;
	rep(i,0,n) if (!c[i]) {
		b[m]=a[i]; profit[m]=pp[i];
		++m;
	}
	rep(i,0,m) {
		int p=max_element(profit,profit+m)-profit;
		if (profit[p]<0) break;
		s+=profit[p];
		profit[p]=inf;
		rep(j,0,p) profit[j]+=b[p];
		rep(j,p,n) profit[j]+=b[j];
	}
	return s;
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	printf("%lld\n",gg());
}