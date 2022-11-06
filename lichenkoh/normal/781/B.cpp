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
const ll mn=1002;
string as[mn][2];
string vans[mn];
map<string,vll> h[2];
set<pair<string,ll> > seen;
queue<pair<string,ll> > q;
void go(string s, ll p) {
	if (seen.find(MP(s,p))==seen.end()) {
		q.push(MP(s,p));
		seen.insert(MP(s,p));
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; cin>>n;
	for (ll i=0;i<n;i++) {
		string team,ht;cin>>team>>ht;
		as[i][0]=team.substr(0,3);
		as[i][1]=team.substr(0,2)+ht.substr(0,1);
		for (ll k=0;k<2;k++) h[k][as[i][k]].PB(i);
	}
	for (ll x=0;x<n;x++) {
		string s=as[x][0];
		if (h[0][s].size()>1) {
			go(s,0);
		}
	}
	bool bad=false;
	while(!q.empty()) {
		auto got=q.front(); q.pop();
		string s=got.first; ll p=got.second;
		for (ll fl=0;fl<=1;fl++) {
			if (fl==1&&p==0) continue;
			for (auto &t:h[fl][s]) {
				if (vans[t]=="") {
					//if (as[t][fl^1]==s) bad=true;
					vans[t]=as[t][fl^1];
					//cout<<t<<as[t][fl^1]<<endl;
					go(as[t][fl^1],1);
				}
			}
		}
	}
	for (ll x=0;x<n;x++) {
		if (vans[x]=="") vans[x]=as[x][0];
	}
	for (ll x=0;x<n;x++) for (ll y=x+1;y<n;y++) if (vans[x]==vans[y]) bad=true;
	if (bad) {
		printf("NO\n"); return 0;
	}
	printf("YES\n");
	for (ll x=0;x<n;x++) {
		string ans=vans[x];
		if (ans=="") ans=as[x][0];
		printf("%s\n",ans.c_str());
	}

}