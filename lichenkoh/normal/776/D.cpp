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
const ll INF=1e9+100;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=1e5+4;
bool seenroom[2][mn];
ll vswitchstate[2][mn];
ll initroomstate[mn];
vector<ll> gswitch[mn];
vector<ll> groom[mn];
ll tried;
bool able;
void dfsswitch(ll sw, ll switchstate);
void dfsroom(ll r) {
	if (seenroom[tried][r]||(!able)) return;
	seenroom[tried][r]=true;
	ll now=initroomstate[r]^1;
	for (auto &sw:groom[r]) {
		if (vswitchstate[tried][sw]!=-1) {
			now^=vswitchstate[tried][sw];
		}
	}
	for (auto &sw:groom[r]) {
		if (vswitchstate[tried][sw]==-1) {
			dfsswitch(sw,now);
			now=0;
		}
	}
	if (now!=0) {
		able=false;
	}
}
void dfsswitch(ll sw, ll switchstate) {
	if (vswitchstate[tried][sw]!=-1) return;
	vswitchstate[tried][sw]=switchstate;
	//printf("tried:%d sw:%d state:%d\n",tried,sw,switchstate);
	for (auto &r:gswitch[sw]) {
		dfsroom(r);
	}
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m; scanf("%d%d",&n,&m);
	for (ll i=1;i<=n;i++) scanf("%d",&initroomstate[i]);
	for (ll sw=0;sw<m;sw++) {
		ll t; scanf("%d",&t);
		for (ll j=0;j<t;j++) {
			ll r; scanf("%d",&r);
			groom[r].PB(sw);
			gswitch[sw].PB(r);
		}
	}
	memset(seenroom,0,sizeof seenroom);
	memset(vswitchstate,-1,sizeof vswitchstate);
	for (ll sw=0;sw<m;sw++) {
		bool can=false;
		for (ll t=0;t<2;t++) {
			tried=t;
			able=true;
			dfsswitch(sw,t);
			if (able) can=true;
		}
		if (!can) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}