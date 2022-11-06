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

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string aa,bb; cin>>aa>>bb;
	set<string> s;
	s.insert(aa); s.insert(bb);
	cout<<aa<<" "<<bb<<endl;
	ll n; cin>>n;
	for (ll i=0;i<n;i++) {
		string murder,next;
		cin>>murder>>next;
		s.erase(murder);
		s.insert(next);
		for (auto &w:s) {
			cout<<w<<" ";
		}
		cout<<endl;
	}
}