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
int main() {
	ios_base::sync_with_stdio(false);
	ll n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	ll **f=new ll*[a];
	for (ll i=0;i<a;i++) {
		f[i]=new ll[b];
	}
	ll t=1;
	for (ll x=0;x<a;x++) {
		if (b%2==0&&x%2==1) {
			for (ll y=b-1;y>=0;y--) {
				f[x][y]=(t>n)?0:t;
				t++;
			}
		}
		else {
			for (ll y=0;y<b;y++) {
				f[x][y]=(t>n)?0:t;
				t++;
			}
		}
	}
	if (t>n) {
		for (ll x=0;x<a;x++) {
			for (ll y=0;y<b;y++) {
				printf("%d ",f[x][y]);
			}
			printf("\n");
		}
	}
	else {
		printf("-1\n");
	}
}