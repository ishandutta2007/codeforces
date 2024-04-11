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
ll a[1004];
ll f[104][104];
bool vowel(char x) {
	return (x=='a')||(x=='e')||(x=='i')||(x=='o')||(x=='u')||(x=='y');
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll nn; cin>>nn;
	for (ll i=0;i<nn;i++) cin>>a[i];
	{
		string s;getline(cin,s);
	}
	bool ans=true;
	for (ll i=0;i<nn;i++) {
		string s;
		getline(cin,s);
		//cout<<s<<endl;
		ll n=s.length();
		ll v=0;
		for (ll x=0;x<n;x++) {
			if (vowel(s[x])) v++;
		}
		if (v!=a[i])ans=false;
	}
	if (ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}