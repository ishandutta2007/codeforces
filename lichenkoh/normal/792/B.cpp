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
typedef vector<pll> vpll;

int a[200];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,k; scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) {int x; scanf("%d",&a[i]);}
	vll v; for (int i=0;i<n;i++) v.PB(i+1);
	int leader=0;
	for (int t=0;t<k;t++) {
		int elim=(leader+a[t])%v.size();
		printf("%d ",v[elim]);
		if (t==k-1) break;
		v.erase(v.begin()+elim);
		leader=(elim)%v.size();
	}
	printf("\n");
}