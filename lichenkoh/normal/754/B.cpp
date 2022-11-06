#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
string a[6];
ll vdx[4]={0,1,1,1};
ll vdy[4]={1,0,1,-1};
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (ll x=1;x<=4;x++) cin>>a[x];
	for (ll x=1;x<=4;x++) {
		a[x].resize(6);
		for (ll y=5;y>=1;y--) a[x][y]=a[x][y-1];
	}
	for (ll x=1;x<=4;x++) for (ll y=1;y<=4;y++) {
		for (ll k=0;k<4;k++) {
			ll dx=vdx[k],dy=vdy[k];
			ll cnt=0;
			for (ll t=-1;t<=1;t++) {
				ll nx=x+dx*t,ny=y+dy*t;
				char c=a[nx][ny];
				if (c=='x') cnt++;
				if (c=='o') cnt=-100;
				if (!(1<=nx&&nx<=4&&1<=ny&&ny<=4)) cnt=-100;
			}
			if (cnt>=2) {
				printf("YES\n"); return 0;
			}
		}
	}
	printf("NO\n");
}