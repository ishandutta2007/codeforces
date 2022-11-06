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
const ll INF=2e9+4;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const int mn=2e5+4;
ll a[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int least=INF;
	for (int i=0;i<n-1;i++) chkmin(least,a[i+1]-a[i]);
	int cnt=0;
	for (int i=0;i<n-1;i++) if(least==a[i+1]-a[i]) cnt++;
	printf("%d %d\n",least,cnt);
}