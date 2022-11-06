#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
const ll mn=1e5+4;
ll a[mn];
ll s[mn];
bool seen[mn];
vector<vector<ll> > v[2][2];
vector<ll> ans;
ll n;
pair<ll,vector<ll> > solve(ll ask) {
	// Start with L->R goes to L
	ans.clear();
	bool done=false;
	ll now=0;
	for (auto &w:v[0][1]) {
		for (auto &x:w) {
			ans.PB(x); now^=1;
			if (ask&&now==1&&!done) {
				done=true;
				for (auto &w:v[1][0]) for (auto &x:w) ans.PB(x);
			}
		}
		if (now==1&&!done) {
			done=true;
			for (auto &w:v[1][0]) for (auto &x:w) ans.PB(x);
		}
	}
	// Start with L->L goes to R
	ll i00=0,i11=0;
	if (v[0][0].size()) {
		for (auto &x:v[0][0][0]) {
			ans.PB(x);
			now^=1;
			if (ask&&now==1&&!done) {
				done=true;
				for (auto &w:v[1][0]) for (auto &x:w) ans.PB(x);
			}
		}
		i00++;
	}
	if (now==1&&!done) {
		done=true;
		for (auto &w:v[1][0]) for (auto &x:w) ans.PB(x);
	}
	if (v[0][0].size()) {while(i11<v[1][1].size()) {
		for (auto &x:v[1][1][i11]) {
			ans.PB(x);
			now^=1;
			if (ask&&now==1&&!done) {
				done=true;
				for (auto &w:v[1][0]) for (auto &x:w) ans.PB(x);
			}
		}
		if (now==1&&!done) {
			done=true;
			for (auto &w:v[1][0]) for (auto &x:w) ans.PB(x);
		}
		i11++;
		if (i00<v[0][0].size()) {
			for (auto &x:v[0][0][i00]) {
				ans.PB(x);
				now^=1;
				if (ask&&now==1&&!done) {
					done=true;
					for (auto &w:v[1][0]) for (auto &x:w) ans.PB(x);
				}
			}
			i00++;
			if (now==1&&!done) {
				done=true;
				for (auto &w:v[1][0]) for (auto &x:w) ans.PB(x);
			}
		}
		else break;
	}}
	//printf("anssz:%d n:%d\n",ans.size(),n);
	if (ans.size()!=n) return MP(INF,ans);
	ll cost=0;
	//for (ll i=0;i<n;i++) printf("(%d %d) ",ans[i]+1,s[ans[i]]);
	//printf("\n");
	for (ll i=1;i<n;i++) {
		assert(s[ans[i]]!=s[ans[i-1]]);
		if (ans[i]<ans[i-1]) cost++;
	}
	return MP(cost,ans);
}
int main() {
	string ss;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>ss;
	n=ss.length();
	for (ll i=0;i<n;i++) {
		s[i]=(ss[i]=='R');
	}
	vector<ll> vl,vr;
	for (ll i=0;i<n;i++) {
		if (!s[i]) vl.PB(i);
		else vr.PB(i);
	}
	ll il=0,ir=0;
	for (ll x=0;x<n;x++) a[x]=-1;
	for (ll x=0;x<n;x++) {
		if (!s[x]) {
			while(ir<vr.size()) {
				if (vr[ir]>x) break;
				ir++;
			}
			if (ir<vr.size()) {
				a[x]=vr[ir];
				ir++;
			}
		}
		else {
			while(il<vl.size()) {
				if (vl[il]>x) break;
				il++;
			}
			if (il<vl.size()) {
				a[x]=vl[il];
				il++;
			}
		}
	}
	memset(seen,0,sizeof seen);
	for (ll xx=0;xx<n;xx++) {
		ll x=xx;
		if (!seen[x]) {
			ll first=s[x];
			ll last;
			vector<ll> tmp;
			while(x!=-1&&!seen[x]) {
				tmp.PB(x);
				seen[x]=true;
				x=a[x];
			}
			last=s[tmp[tmp.size()-1]];
			v[first][last].PB(tmp);
		}
	}
	/*
	for (ll first=0;first<2;first++) for (ll last=0;last<2;last++) {
			for (auto &w:v[first][last]) {
				for (auto &x:w)printf("%d ",x+1);
				printf("dbg %d %d\n",first,last);
			}
	}
	*/
	pair<ll,vector<ll> > best=solve(false);
	chkmin(best,solve(true));
	swap(v[0][0],v[1][1]);
	swap(v[0][1],v[1][0]);
	chkmin(best,solve(false));
	chkmin(best,solve(true));
	printf("%d\n",best.first);
	for (auto &w:best.second) {
		printf("%d ",w+1);
	}
	assert(best.first<INF);
}