#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
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
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,x;
	scanf("%d",&n);
	ll same=-1;
	bool ans=true;
	for (ll i=0;i<n;i++) {
		scanf("%d",&x);
		while(x%2==0) x/=2;
		while(x%3==0) x/=3;
		if (i==0) same=x;
		else if (x!=same) ans=false;
	}
	if (ans) printf("Yes\n");
	else printf("No\n");
}