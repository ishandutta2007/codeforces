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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;
string bad="===";
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; string s;
	cin>>n>>s;
	if (n%4!=0) {
		cout<<bad<<endl;
		return 0;
	}
	ll t=n/4;
	map<char,ll> h;
	queue<ll> q;
	for (ll i=0;i<n;i++) {
		char w=s[i];
		if (w!='?') h[w]++;
		else q.push(i);
	}
	char cl[]={'A','C','T','G'};
	for (ll i=0;i<4;i++) {
		char c=cl[i];
		ll have=t-h[c];
		if (have<0) {
			cout<<bad<<endl; return 0;
		}
		else {
			for (ll j=0;j<have;j++) {
				if (q.empty()) {
					cout<<bad<<endl; return 0;
				}
				ll idx=q.front(); q.pop();
				s[idx]=c;
			}
		}
	}
	cout<<s<<endl;
}