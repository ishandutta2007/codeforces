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
string a[2];
vector<ll> v[2][2];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>a[0]>>a[1];
	ll n=a[0].length();
	ll k=n;
	while(k%2==0) k/=2;
	ll cur=0,nxt=1;
	{
		ll sidx=0;
		map<string,ll> hstr;
		for (ll t=0;t<2;t++) {
			for (ll x=0;x<n;x+=k) {
				string s=a[t].substr(x,k);
				ll key;
				auto it=hstr.find(s);
				if (it==hstr.end()) {
					key=sidx;
					hstr[s]=sidx++;
				}
				else key=it->snd;
				v[cur][t].PB(key);
				//printf("t:%d s:%s x:%d k:%d key:%d\n",t,s.c_str(),x,k,key);
			}
		}
	}
	for(;k!=n;k*=2) {
		for (ll t=0;t<2;t++) v[nxt][t].clear();
		ll vsz=v[cur][0].size();
		map<pll,ll> h;
		ll sidx=0;
		for (ll t=0;t<2;t++) {
			for (ll x=0;x<vsz;x+=2) {
				pll s=MP(v[cur][t][x],v[cur][t][x+1]);
				ll key;
				auto it=h.find(s);
				if (it==h.end()) {
					key=sidx;
					h[s]=sidx;
					h[MP(s.snd,s.fst)]=sidx;
					sidx++;
				}
				else key=it->snd;
				//printf("t:%d x:%d key:%d\n",t,x,key);
				v[nxt][t].PB(key);
			}
		}
		swap(cur,nxt);
	}
	if (v[cur][0]==v[cur][1]) printf("YES\n");
	else printf("NO\n");
}