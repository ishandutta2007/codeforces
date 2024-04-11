#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

struct Trie{
	struct TrieNode{
		int num, next[26];
		TrieNode(){
			num = 0;
			for(int i = 0; i < 26; i++) next[i] = -1;
		}
	};
	vector<TrieNode> vec;
	Trie(){
		init();
	}
	void init(){
		vec.clear();
		vec.push_back(TrieNode());
	}
	int seek(string &s)
	{
		int p = 0;
		for(int i = 0; i < s.size(); i++){
			int c = s[i]-'a';
			if(vec[p].next[c] == -1){
				vec.push_back(TrieNode());
				vec[p].next[c] = (int)vec.size()-1;
			}
			p = vec[p].next[c];
		}
		return p;
	}
	void insert(string &s, int x = 1)
	{
		int p = seek(s);
		vec[p].num += x;
	}
	void erase(string &s, int x = 1)
	{
		int p = seek(s);
		vec[p].num = max(0, vec[p].num - x);
	}
	int count(string &s)
	{
		int p = seek(s);
		return vec[p].num;
	}
};

struct HLD{
	int V, logV;
	vector<P> mp;
	map<P, int> mp2;
	vector<P> parent;
	
	//subtree of v is [pre_order[v], back_order[v]]
	vector<int> pre_order;
	vector<int> back_order;
	
	int order;
	int global_id, local_id;
	vector<int> size, depth;
	vector<vector<int> > prev;
	
	HLD(){}
	
	void predfs(vector<int> G[], int v, int p, int d)
	{
		size[v] = 1, depth[v] = d, prev[v][0] = p;
		for(int i = 0; i < G[v].size(); i++){
			if(G[v][i] == p) continue;
			predfs(G, G[v][i], v, d+1);
			size[v] += size[G[v][i]];
		}
	}
	void maindfs(vector<int> G[], int v, int p)
	{
		mp[v] = make_pair(global_id, local_id);
		mp2[make_pair(global_id, local_id)] = v;
		pre_order[v] = ++order;
		
		if(G[v].size() == 1 && G[v][0] == p){
			back_order[v] = order;
			return;
		}
		
		vector<P> vec;
		for(int i = 0; i < G[v].size(); i++){
			if(G[v][i] == p) continue;
			vec.push_back(make_pair(size[G[v][i]], G[v][i]));
		}
		sort(vec.rbegin(), vec.rend());
		
		local_id++;
		if(vec.size() >= 1) maindfs(G, vec[0].second, v);
			
		for(int i = 1; i < vec.size(); i++){
			parent.push_back(mp[v]);
			global_id++, local_id = 0;
			maindfs(G, vec[i].second, v);
		}
		back_order[v] = order;
	}
	int getLCA(int u, int v){
		int x = u, y = v;
		if(depth[y] > depth[x]) swap(x, y);
		
		for(int i = logV-1; i >= 0; i--){
			if(depth[x] - (1<<i) >= depth[y]) x = prev[x][i];
		}
		if(x == y) return x;
		for(int i = logV-1; i >= 0; i--){
			if(prev[x][i] != prev[y][i]){
				x = prev[x][i];
				y = prev[y][i];
			}
		}
		x = prev[x][0];
		return x;
	}
	void pathcalc(int v, int lca, vector<pair<int, P> > &dest)
	{
		int gid = mp[v].first, lid = mp[v].second;
		int Gid = mp[lca].first, Lid = mp[lca].second;
		
		while(Gid != gid){
			dest.push_back(make_pair(gid, make_pair(0, lid)));
			int ngid = parent[gid].first, nlid = parent[gid].second;
			gid = ngid, lid = nlid;
		}
		dest.push_back(make_pair(gid, make_pair(Lid, lid)));
	}
	
	void init(vector<int> G[], int V) // The tree must be 1-indexed.
	{
		this->V = V, logV = 0;
		for(int t = V; t; t/=2) logV++;
		prev.resize(V+1);
		for(int i = 0; i <= V; i++) prev[i].resize(logV);
		
		size.resize(V+1), depth.resize(V+1);
		predfs(G, 1, 0, 0);
		
		prev[0][0] = 0;
		for(int i = 1; i < logV; i++){
			for(int j = 1; j <= V; j++){
				prev[j][i] = prev[prev[j][i-1]][i-1];
			}
		}
		
		mp.resize(V+1), mp2.clear();
		parent.clear(), parent.push_back(make_pair(-1, -1));
		pre_order.resize(V+1), back_order.resize(V+1);
		global_id = local_id = 0, order = 0;
		
		maindfs(G, 1, 0);
	}
	
	void path(int u, int v, vector<pair<int, P> > &dest)
	{
		dest.clear();
		int lca = getLCA(u, v);
		pathcalc(u, lca, dest);
		pathcalc(v, lca, dest);
		
		pair<int, P> p = make_pair(mp[lca].first, make_pair(mp[lca].second, mp[lca].second));
		for(int i = 0; i < dest.size(); i++){
			if(dest[i] == p){
				dest.erase(dest.begin()+i);
				return ;
			}
		}
	}
	
	void getPath(int u, int v, vector<P> &dest) //transform an u-v path into intervals[l, r] on segtree.
	{
		vector<pair<int, P> > src;
		path(u, v, src);
		
		dest.clear();
		for(int i = 0; i < src.size(); i++){
			int u = mp2[make_pair(src[i].first, src[i].second.first)], v = mp2[make_pair(src[i].first, src[i].second.second)];
			dest.push_back(make_pair(pre_order[u], pre_order[v]));
		}
	}
};

// range-add, range-min query
 
struct LazySegTree{
	int size;
	vector<llint> seg, delay;
	
	LazySegTree(){}
	LazySegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
		delay.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++){
			seg[i] = inf;
			delay[i] = 0;
		}
	}
	
	void eval(int l, int r, int k)
	{
		if(delay[k]){
			seg[k] += delay[k];  //
			if(l < r){
				delay[k*2] += delay[k];
				delay[k*2+1] += delay[k];
			}
			delay[k] = 0;
		}
	}
	
	void update(int i, llint val)
	{
		int l = 0, r = (1<<size)-1, k = 1;
		eval(l, r, k);
		for(int j = size-1; j >= 0; j--){
			k <<= 1;
			if(i & (1<<j)){
				k++;
				r = (l+r)/2;
			}
			else l = (l+r)/2+1;
			eval(l, r, k);
		}
		
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = min(seg[i*2], seg[i*2+1]);
		}
	}
	
	void add(int a, int b, int k, int l, int r, llint val)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			delay[k] += val;
			eval(l, r, k);
			return;
		}
		add(a, b, k*2, l, (l+r)/2, val);
		add(a, b, k*2+1, (l+r)/2+1, r, val);
		seg[k] = min(seg[k*2], seg[k*2+1]);
	}
	void add(int a, int b, llint val){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val);
	}
 
	llint query(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return inf;
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return min(lval, rval);
	}
	llint query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

ll n, F;
string s[100005];
Trie trie;
vector<int> G[100005];
int sum[100005];
vector<P> vec;
HLD hld;
LazySegTree seg(17);

void dfs(int v, int d)
{
	vec.push_back(P(d, v+1));
	ll ret = trie.vec[v].num;
	rep(j, 0, 25){
		if(trie.vec[v].next[j] != -1){
			int u = trie.vec[v].next[j];
			dfs(u, d+1);
			ret += sum[u+1];
		}
	}
	sum[v+1] = ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> s[i], trie.insert(s[i]);
	dfs(0, 0);
	
	ll m = trie.vec.size();
	rep(i, 0, m-1) rep(j, 0, 25) if(trie.vec[i].next[j] != -1){
		ll v = trie.vec[i].next[j];
		G[i+1].push_back(v+1);
		G[v+1].push_back(i+1);
	}
	hld.init(G, m);
	
	vector<P> res;
	rep(i, 1, m){
		hld.getPath(i, i, res);
		for(auto p : res) seg.add(p.first, p.second, sum[i]);
	}
	
	sort(all(vec));
	ll ans = 0;
	for(auto p : vec){
		ll v = p.second, w = p.first, ret = inf;
		if(v == 1) continue;
		hld.getPath(1, v, res);
		for(auto p : res) chmin(ret, seg.query(p.first, p.second));
		if(ret <= 0) continue;
		ans += w;
		for(auto p : res) seg.add(p.first, p.second, -1);
	}
	cout << ans << endl;
	
	return 0;
}