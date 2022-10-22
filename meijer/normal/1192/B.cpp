#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef tuple<ll, ll, ll, ll> iiii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<iiii> viiii;
typedef vector<ll> vll;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(ll a=ll(c-1); a>=ll(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const ll MX=1e5+1e4, MOD=1e9+7, SUB=18*MX;
ll n, q, w, a, b, c;
vii edges;
ll edgeWeight[MX];
map<ll, ll> adjList[MX];
ll size[MX], subTrees=0;
viiii edgeUpdates[MX];
ll regions[SUB], segSize[SUB];
vi regionBegin[SUB], regionEnd[SUB];
vi SEG[SUB], LAZY[SUB];
map<ll, ll> bestRegions[SUB];
map<ll, ll> allAnses;

ll dfsSize(ll u, ll p=-1) {
	size[u] = 1;
	for(ii v:adjList[u])
		if(v.fi != p)
			size[u] += dfsSize(v.fi, u);
	return size[u];
}
ll dfsCentroid(ll u, ll p, ll subSize) {
	for(ii v:adjList[u])
		if(v.fi != p)
			if(size[v.fi] > subSize)
				return dfsCentroid(v.fi, u, subSize);
	return u;
}
ll getCentroid(ll u) {
	return dfsCentroid(u, -1, dfsSize(u)/2);
}
ll dfsSubTree(ll u, ll p, ll region) {
	bool first=1;
	for(ii v:adjList[u]) if(v.fi != p) {
		if(first) first = 0;
		else region++;
		ll beg = region;
		region = dfsSubTree(v.fi, u, region);
		edgeUpdates[v.se].pb(iiii{subTrees,beg,region,regions[subTrees]});
	}
	return region;
}
void handleSubTree(ll u) {
    if(adjList[u].size() == 0) return;
	u = getCentroid(u);

	regions[subTrees] = 0;
	regionBegin	[subTrees].resize(adjList[u].size());
	regionEnd	[subTrees].resize(adjList[u].size());
	ll region = -1;
	for(ii v:adjList[u]) {
		regionBegin	[subTrees][regions[subTrees]] = ++region;
		ll beg = region;
		region = dfsSubTree(v.fi, u, region);
		edgeUpdates[v.se].pb(iiii{subTrees,beg,region,regions[subTrees]});
		regionEnd 	[subTrees][regions[subTrees]] = region;
		regions[subTrees]++;
	}
	segSize[subTrees] = ++region;
	SEG [subTrees].assign(segSize[subTrees]*4, 0);
	LAZY[subTrees].assign(segSize[subTrees]*4, 0);
	subTrees++;

	for(ii v:adjList[u]) {
		adjList[v.fi].erase(u);
		handleSubTree(v.fi);
	}
	adjList[u].clear();
}
void addSeg(ll x, ll i, ll j, ll v, ll lazy, ll p, ll l, ll r) {
	SEG [x][p] += lazy;
	LAZY[x][p] += lazy;
	if(j < l || i > r) return;
	if(i <= l && j >= r) {
		SEG [x][p] += v;
		LAZY[x][p] += v;
	} else {
		ll m=(l+r)/2;
		addSeg(x,i,j,v,LAZY[x][p],p*2+1,l,m);
		addSeg(x,i,j,v,LAZY[x][p],p*2+2,m+1,r);
		LAZY[x][p] = 0;
		SEG[x][p] = max(SEG[x][p*2+1], SEG[x][p*2+2]);
	}
}
ll getSeg(ll x, ll i, ll j, ll lazy, ll p, ll l, ll r) {
	SEG [x][p] += lazy;
	LAZY[x][p] += lazy;
	if(j < l || i > r) return 0;
	if(i <= l && j >= r) return SEG[x][p];
	ll m=(l+r)/2;
	ll a = getSeg(x,i,j,LAZY[x][p],p*2+1,l,m);
	ll b = getSeg(x,i,j,LAZY[x][p],p*2+2,m+1,r);
	LAZY[x][p] = 0;
	SEG[x][p] = max(SEG[x][p*2+1], SEG[x][p*2+2]);
	return max(a,b);
}
ll getAnsSubtree(ll i) {
	auto it = --bestRegions[i].end();
	ll curAns = it->fi;
	if(regions[i] != 1) {
		if(it->se == 1) it--;
		curAns += it->fi;
	}
	return curAns;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q>>w;
    RE(i,n-1) {
    	cin>>a>>b>>c, a--, b--;
    	adjList[a][b] = i;
    	adjList[b][a] = i;
    	edgeWeight[i] = c;
    	edges.pb({a,b});
    }
    handleSubTree(0);
    RE(i,n-1) {
    	for(iiii v:edgeUpdates[i]) {
	    	ll subTree, l, r, region;
	    	tie(subTree, l, r, region) = v;
	    	addSeg(subTree, l, r, edgeWeight[i],0,0,0,segSize[subTree]-1);
    	}
    }
    RE(i,subTrees) {
    	RE(j,regions[i]) {
    	    ll Beg = regionBegin[i][j];
    	    ll End = regionEnd  [i][j];
    	    ll mx  = getSeg(i,Beg,End,0,0,0,segSize[i]-1);
    		bestRegions[i][mx]++;
    	}
    	allAnses[getAnsSubtree(i)]++;
	}

	ll last = 0;
	RE(i,q) {
		ll d, e;
		cin>>d>>e;
		d = (d+last)%(n-1);
		e = (e+last)%w;
    	for(iiii v:edgeUpdates[d]) {
	    	ll subTree, l, r, region;
	    	tie(subTree, l, r, region) = v;

	    	ll curAns = getAnsSubtree(subTree);
    		allAnses[curAns]--;
    		if(allAnses[curAns] == 0)
    			allAnses.erase(curAns);

    	    ll Beg = regionBegin[subTree][region];
    	    ll End = regionEnd  [subTree][region];
    	    ll mx  = getSeg(subTree,Beg,End,0,0,0,segSize[subTree]-1);
    		bestRegions[subTree][mx]--;
    		if(bestRegions[subTree][mx] == 0)
    			bestRegions[subTree].erase(mx);

	    	addSeg(subTree, l, r,-edgeWeight[d],0,0,0,segSize[subTree]-1);
	    	addSeg(subTree, l, r, e,0,0,0,segSize[subTree]-1);

    	    mx  = getSeg(subTree,Beg,End,0,0,0,segSize[subTree]-1);
    		bestRegions[subTree][mx]++;

    		allAnses[getAnsSubtree(subTree)]++;
    	}
	    edgeWeight[d] = e;
    	last = (--allAnses.end())->fi;
    	cout<<last<<endl;
	}
}