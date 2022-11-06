#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN = 3*100*1000 + 50;
int a[MAXN];
int b[MAXN];
ll n,k;
ll ok(ll imid) {
	for (ll x=0;x<=n;x++) {
		ll y=x+imid;
		ll sum=b[y]-b[x];
		if (sum>=imid-k) return x;
		if (y>n) break;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	scanf("%d %d",&n,&k);
	a[0]=0;
	for (ll i=0;i<n;i++) {
		scanf("%d",&a[i+1]);
	}
	for (ll i=0;i<=n;i++) b[i]=a[i];
	for (ll i=1;i<=n;i++) b[i]+=b[i-1];
	ll imin=0; ll imax=n+1;
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		if (ok(imid) != -1) {
			imin=imid+1;
		}
		else {
			imax=imid;
		}
	}
	imin--;
	ll sol=ok(imin);
	if (sol!=-1) {
		sol++;
		printf("%d\n",imin);
		for (ll x=sol;x<sol+imin;x++) {
			a[x]=1;
		}
		for (ll x=1;x<=n;x++) {
			printf("%d ",a[x]);
		}
		printf("\n");
	}
	else {
		printf("0\n\n");
	}
}