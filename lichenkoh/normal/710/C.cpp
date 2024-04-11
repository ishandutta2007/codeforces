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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=100;
ll a[mn][mn];
ll b[mn][mn];
int main() {
	ios_base::sync_with_stdio(false);
	int n;scanf("%d",&n);
	ll m=(n+1)/2;
	for (ll k=0;k<m;k++) {
		for (ll y=k;y<m;y++) {
			a[k][y]=(k&1)^1;
		}
		for (ll x=k;x<m;x++) {
			a[x][k]=(k&1)^1;
		}
	}
	ll d=m-1;
	for (ll x=0;x<m;x++) for (ll y=0;y<m;y++) {
		b[d+x][d+y]=a[x][y];
		b[d-x][d-y]=a[x][y];
		b[d+x][d-y]=a[x][y];
		b[d-x][d+y]=a[x][y];
	}
	ll odd=1,even=2;
	for (ll x=0;x<n;x++) {for (ll y=0;y<n;y++) {
		if (b[x][y]%2) {printf("%d ",odd); odd+=2;}
		else {printf("%d ",even); even+=2;}
	}printf("\n");
	}
}