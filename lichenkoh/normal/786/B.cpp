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
const int mn=1e5+4;
set<int> te[2*mn];
int segEdgeN;
void addedge(set<int> &s, int val, bool toadd) {
	if (toadd) s.insert(val);
	else s.erase(val);
}

void segModifyEdge(int l, int r, int value, bool toadd) {
	++r;
  for (l += segEdgeN, r += segEdgeN; l < r; l >>= 1, r >>= 1) {
    if (l&1) addedge(te[l++], value, toadd);
    if (r&1) addedge(te[--r], value, toadd);
  }
}

set<int> segQueryEdge(int p) {
  set<int> res;
  for (p += segEdgeN; p > 0; p >>= 1) {
  	for (auto &w:te[p]) res.insert(w);
  }
  return res;
}


typedef struct edget {
	int sl,sr,tl,tr,w;
} edge;

vector<edge> ve;
ll vans[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,q,s; scanf("%d%d%d",&n,&q,&s);
	segEdgeN=n+1;
	for (int i=0;i<q;i++) {
		int t; scanf("%d",&t);
		int sl,sr,tl,tr,w;
		if (t==1) {
			int v,u;
			scanf("%d%d%d",&v,&u,&w);
			sl=v,sr=v,tl=u,tr=u;
		}
		else {
			int v,l,r;
			scanf("%d%d%d%d",&v,&l,&r,&w);
			if (t==2) sl=v,sr=v,tl=l,tr=r;
			else sl=l,sr=r,tl=v,tr=v;
		}
		edge e={sl,sr,tl,tr,w};
		ve.PB(e);
		//printf("sl:%d sr:%d i:%d\n",sl,sr,i);
		segModifyEdge(sl,sr,ve.size()-1,true);
	}
	memset(vans,-1,sizeof vans);
	set<ll> active;
	for (ll x=1;x<=n;x++) active.insert(x);
	map<ll,pair<vector<int>, vector<int> > > h;
	h[0].fst.PB(s);
	active.erase(s);
	ll prev=-1;
	while(1) {
			auto jt=h.upper_bound(prev);
			if (jt==h.end()) break;
			ll dist=jt->first;
			prev=dist;
			// Process edge
			for (auto &ei:jt->second.snd) {
				edge e=ve[ei];
				auto it=active.lower_bound(e.tl); 
				while(1) {
					if (it==active.end()||*it > e.tr) break;
					h[dist].fst.PB(*it);
					it=active.erase(it);
					if (it==active.end()||*it > e.tr) break;
				}
			}
			// Process vtx
			for (auto &vtx:jt->second.fst) {
				vans[vtx]=dist;
				//printf("vtx:%d dist:%d\n",vtx,dist);
				set<int> edgeIdxSet=segQueryEdge(vtx);
				for (auto &ei: edgeIdxSet) {
					edge e=ve[ei];
					h[dist+e.w].snd.PB(ei);
					//printf("ei:%d newdist:%d\n",ei,dist+e.w);
					segModifyEdge(e.sl,e.sr,ei,false);
				}
			}
	}
	for (ll x=1;x<=n;x++) printf("%lld ",vans[x]);
	printf("\n");
}