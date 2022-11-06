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
const ll MAXN=1000000+4;
int a[MAXN];
int h[MAXN];
int f[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	ll n,m; scanf("%d %d",&n,&m);
	for (ll i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	for (ll i=0;i<MAXN;i++) {h[i]=0; f[i]=0;}
	for (ll i=0;i<n;i++) {
		if (a[i]<=m) {
			h[a[i]]++;
		}
	}
	for (ll x=1;x<=m;x++) {
		for (ll y=x;y<=m;y+=x) {
			f[y]+=h[x];
		}
	}
	ll best=-1,besty=-1;
	for (ll y=1;y<=m;y++) {
		if (f[y]>best) {
			best=f[y];
			besty=y;
		}
	}
	printf("%d %d\n",besty,best);
	for (ll i=0;i<n;i++) {
		if ((besty%a[i])==0) {
			printf("%d ",i+1);
		}
	}
	printf("\n");
}