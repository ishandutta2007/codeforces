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
string g[2];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin>>s;
	ll slen=s.length();
	ll a,b;
	for (ll x=0;x<slen;x++) for (ll y=x+1;y<slen;y++) {
		if (s[x]==s[y]) a=x,b=y;
	}
	//cout<<a<<","<<b<<endl;
	if (abs(b-a)==1) cout<<"Impossible"<<endl;
	else if (abs(b-a)%2==0) {
		g[0].resize(13);g[1].resize(13);
		ll r=(b-a-2)/2;
		ll x=0;
		ll y=12-r;
		for (ll i=b;i<slen;i++) {
			g[x][y]=s[i];
			if (x==0) {
				if (y>0) y--;
				else x=1;
			}
			else {
				y++;
			}
		}
		for (ll i=0;i<a;i++) {
			g[x][y]=s[i];
			if (x==0) {
				if (y>0) y--;
				else x=1;
			}
			else {
				y++;
			}
		}
		x=0;
		y=12-r;
		for (ll i=a;i<b;i++) {
			g[x][y]=s[i];
			if (x==0) {
				if (y<12) y++;
				else x=1;
			}
			else {
				y--;
			}
		}
		cout<<g[0]<<endl;
		cout<<g[1]<<endl;
	}
	else {
		g[0].resize(13);g[1].resize(13);
		ll r=(b-a)/2;
		ll x=0;
		ll y=12-r;
		for (ll i=b;i<slen;i++) {
			g[x][y]=s[i];
			if (x==0) {
				if (y>0) y--;
				else x=1;
			}
			else {
				y++;
			}
		}
		for (ll i=0;i<a;i++) {
			g[x][y]=s[i];
			if (x==0) {
				if (y>0) y--;
				else x=1;
			}
			else {
				y++;
			}
		}
		x=0;
		y=12-r;
		for (ll i=a;i<b;i++) {
			g[x][y]=s[i];
			if (x==0) {
				if (y<12) y++;
				else x=1;
			}
			else {
				y--;
			}
		}
		cout<<g[0]<<endl;
		cout<<g[1]<<endl;
	}
}