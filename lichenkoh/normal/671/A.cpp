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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ld dist(ld x1,ld y1, ld x2, ld y2) {
	ld dx=(x2-x1);
	ld dy=(y2-y1);
	return sqrt(dx*dx+dy*dy);
}
vector<pair<ld,ll> > v[2];
const ll MAXN=100000+8;
bool use[MAXN];
int cx[MAXN],cy[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	int ax[2],ay[2],tx,ty;
	scanf("%d %d %d %d %d %d",&ax[0],&ay[0],&ax[1],&ay[1],&tx,&ty);
	int n; scanf("%d",&n);
	for (ll i=0;i<n;i++) {
		scanf("%d %d",&cx[i],&cy[i]);
	}
	for (ll j=0;j<2;j++) {
		for (ll i=0;i<n;i++) {
			ld init=2*dist(tx,ty,cx[i],cy[i]);
			ld ifc=dist(ax[j],ay[j],cx[i],cy[i])+dist(tx,ty,cx[i],cy[i]);
			v[j].PB(MP(ifc-init,i));
		}
		sort(v[j].begin(),v[j].end());
	}
	ld final=std::numeric_limits<double>::max();
	for (ll z=1;z<=4;z++) {
		for (ll i=0;i<n;i++) {
			use[i]=false;
		}
		ld ans=0;
		if (z!=4) {
			if (z&1) {
				ll j=0;
				ll idx=0;
				while(idx<n&&use[v[j][idx].second]) {
					idx++;
				}
				if(idx<n) {
					ll i=v[j][idx].second;
					ans+=dist(ax[j],ay[j],cx[i],cy[i])+dist(tx,ty,cx[i],cy[i]);
					use[i]=true;
				}
			}
			if (z&2) {
				ll j=1;
				ll idx=0;
				while(idx<n&&use[v[j][idx].second]) {
					idx++;
				}
				if(idx<n) {
					ll i=v[j][idx].second;
					ans+=dist(ax[j],ay[j],cx[i],cy[i])+dist(tx,ty,cx[i],cy[i]);
					use[i]=true;
				}
			}
			for (ll i=0;i<n;i++) {
				if (!use[i]) {
					ans+=2*dist(tx,ty,cx[i],cy[i]);
				}
			}
		}
		else {
			{
				ll j=1;
				ll idx=0;
				while(idx<n&&use[v[j][idx].second]&&idx<n) {
					idx++;
				}
				if(idx<n) {
					ll i=v[j][idx].second;
					ans+=dist(ax[j],ay[j],cx[i],cy[i])+dist(tx,ty,cx[i],cy[i]);
					use[i]=true;
				}
			}
			{
				ll j=0;
				ll idx=0;
				while(idx<n&&use[v[j][idx].second]&&idx<n) {
					idx++;
				}
				if(idx<n) {
					ll i=v[j][idx].second;
					ans+=dist(ax[j],ay[j],cx[i],cy[i])+dist(tx,ty,cx[i],cy[i]);
					use[i]=true;
				}
			}
			for (ll i=0;i<n;i++) {
				if (!use[i]) {
					ans+=2*dist(tx,ty,cx[i],cy[i]);
				}
			}
		}
		final=min(final,ans);
	}
	cout<<fixed;
	cout<<setprecision(10);
	cout<<final<<endl;
}