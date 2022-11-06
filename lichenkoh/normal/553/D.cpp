#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef double ld;
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
const ll mn=1e5+4;
ll n,m,k;
bitset<mn> isfort;
vll g[mn];
ll alldeg[mn];
ll old_good_deg[mn];
ll gooddeg[mn];
inline ld rat(ll x) {
	return (ld)gooddeg[x]/(ld)alldeg[x];
}
bitset<mn> isrm;
const int MAX_EDGES=mn;
typedef struct graph_t {
	ll gid=0;
	ll from[2*MAX_EDGES];
	ll to[2*MAX_EDGES];
	ll gprev[2*MAX_EDGES];
	ll gnext[2*MAX_EDGES];
	ll head[2*MAX_EDGES];
	void init() { // MUST CALL INIT!!!!
		memset(head,-1,sizeof head);
		gid=0;
	}
	void add_edge_helper(ll x, ll y) {
		from[gid]=x; to[gid]=y;
		gnext[gid]=head[x];
		head[x]=gid;
		gid++;
	}
	void add_edge(ll x, ll y) {
		add_edge_helper(x,y);
		add_edge_helper(y,x);
	}
	void rm_edge_by_id(ll id) {
		ll x=from[id];
		if (head[x]==id) {
			head[x]=gnext[id];
		}
		else {
			gnext[gprev[id]]=gnext[id];
			gprev[gnext[id]]=gprev[id];
		}
	}
	int get_first_edge(ll x) {
		return head[x];
	}
	int get_next_edge_by_id(ll id) {
		return gnext[id];
	}
	int get_src(ll id) {
		return from[id];
	}
	int get_dest(ll id) {
		return to[id];
	}
	int get_opposite_edge(ll id) {
		return id^1;
	}
} graph;
graph oldgraph;
graph newgraph;

bool f(ld r) {
	newgraph=oldgraph;
	memcpy(gooddeg,old_good_deg,sizeof gooddeg);
	isrm=isfort;
	queue<ll> q;
	for (ll x=1;x<=n;x++) {
		if (!isrm[x]&&rat(x)<r) {
			isrm[x]=true;
			q.push(x);
		}
	}
	while(!q.empty()) {
		ll x=q.front(); q.pop();
		ll id=newgraph.get_first_edge(x);
		//printf("x:%d id:%d\n",x,id);
		while(id!=-1) {
			ll y=newgraph.get_dest(id);
			//printf("x:%d->y:%d\n",x,y);
			//newgraph.rm_edge_by_id(id^1);
			gooddeg[y]--;
			if ((!isrm[y])&&rat(y)<r) {
				isrm[y]=true;
				q.push(y);
			}
			id=newgraph.get_next_edge_by_id(id);
		}
	}
	return ((ll)isrm.count()<n);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d%d%d",&n,&m,&k);
	isfort.reset();
	for (ll i=0;i<k;i++) {
		ll fort; scanf("%d",&fort); isfort[fort]=true;
	}
	for (ll i=0;i<m;i++) {
		ll a,b; scanf("%d%d",&a,&b);
		g[a].PB(b);g[b].PB(a);
	}
	for (ll x=1;x<=n;x++) {
		alldeg[x]=g[x].size();
		ll good=0;
		for (auto &y:g[x]) {
			if (!isfort[y]) good++;
		}
		old_good_deg[x]=good;
	}
	oldgraph.init();
	for (ll x=1;x<=n;x++) {
		if (isfort[x]) continue;
		for (auto &y:g[x]) {
			if (isfort[y]) continue;
			if (x<y) oldgraph.add_edge(x,y);
		}
	}
	//assert(!f(0.999));
	ld imin=0,imax=1;
	for (ll k=0;k<45;k++) {
		ld imid=(imin+imax)/2;
		if (f(imid)) imin=imid;
		else imax=imid;
	}
	//printf("%.4f\n",imin);
	
	f(imin);
	ll cnt=n-isrm.count();
	if (cnt==0) {
		printf("1\n");
		for (ll x=1;x<=n;x++) if(!isrm[x]) {
			printf("%d\n",x);
			return 0;
		}
	}
	printf("%d\n",cnt);
	for (ll x=1;x<=n;x++) if(!isrm[x]) {printf("%d ",x);}
	printf("\n");
	
}