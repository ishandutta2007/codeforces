#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll mn=1e5+4;
ll a[mn],p[mn];
bool mark[mn];
int main() {
	ios_base::sync_with_stdio(false);
	ll n,k; scanf("%I64d %I64d",&n,&k);
	for (ll i=0;i<n;i++) {
		scanf("%I64d",&a[i]);
	}
	for (ll i=0;i<k;i++) {
		scanf("%I64d",&p[i]);
		p[i]--;
	}
	ll ans=0;
	ll sum=0;
	for (ll i=0;i<n;i++) {
		ans+=a[i]*a[(i+1)%n];
		//printf("Ord:%I64d\n",a[i]*a[(i+1)%n]);
		sum+=a[i];
	}
	for (ll i=0;i<n;i++) mark[i]=false;
	for (ll j=0;j<k;j++) {
		ll i=p[j];
		ll add=sum;
		if(!mark[(i-1+n)%n]) add-=a[(i-1+n)%n];
		if(!mark[(i+1+n)%n]) add-=a[(i+1+n)%n];
		add-=a[i];
		ll go=add*a[i];
		ans+=go;
		//printf("go %I64d. add:%I64d\n",go,add);
		sum-=a[i];
		mark[i]=true;
	}
	printf("%I64d\n",ans);
}