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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
bool isbin(string &s) {
	return s[0]=='0'||s[0]=='1';
}
const ll mn=5002;
ll n,m;
string lhs[mn],eq,rhs1[mn],op[mn],rhs2[mn];
unordered_map<string,vll> h;
ll final[2*1002];
void solve() {
	h.clear();
	{
		vll v; v.resize(2*m);
		for (ll x=0;x<2*m;x++) {
			v[x]=(x>=m)?1:0;
		}
		h["?"]=v;
	}
	for (ll i=0;i<n;i++) {
		vll ans;
		ans.resize(2*m);
		if (isbin(rhs1[i])) {
			for (ll x=0;x<2*m;x++) {
				ans[x]=(rhs1[i][x%m]=='1')?1:0;
				final[x]+=ans[x];
			}
		}
		else {
			vll l=h[rhs1[i]],r=h[rhs2[i]];
			ans.resize(2*m);
			for (ll x=0;x<2*m;x++) {
				if (op[i]=="XOR") ans[x]=l[x]^r[x];
				else if (op[i]=="AND") ans[x]=l[x]&r[x];
				else if (op[i]=="OR") ans[x]=l[x]|r[x];
				final[x]+=ans[x];
			}
		}
		h[lhs[i]]=ans;
	}
}
int main() 
{
  h.reserve(32768); //updated !
  h.max_load_factor(0.25); //updated !
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
	for (ll i=0;i<n;i++) {
		cin>>lhs[i]>>eq>>rhs1[i];
		if (!isbin(rhs1[i])) {
			cin>>op[i]>>rhs2[i];
		}
	}
	solve();
	string lo,hi; lo.resize(m); hi.resize(m);
	for (ll k=0;k<m;k++) {
		ll res0=final[k];
		ll res1=final[m+k];
		if (res0==res1) {
			lo[k]='0'; hi[k]='0';
		}
		else if (res0<res1) {
			lo[k]='0'; hi[k]='1';
		}
		else if (res1<res0) {
			lo[k]='1'; hi[k]='0';
		}
		else assert(false);
	}
	cout<<lo<<"\n"<<hi<<"\n";
}