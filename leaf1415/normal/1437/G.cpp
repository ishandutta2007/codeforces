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
#define rep(x, s, t) for(int (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e9+7
#define mod 998244353

using namespace std;

typedef pair<int, int> P;

struct SegTree{
	int size;
	vector<int> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = -inf;
	}
	
	void update(int i, int val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = max(seg[i*2], seg[i*2+1]);
		}
	}

	int query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return -inf;
		if(a <= l && r <= b) return seg[k];
		int lval = query(a, b, k*2, l, (l+r)/2);
		int rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return max(lval, rval);
	}
	int query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

struct AhoCorasick{
	struct TrieNode{
		int num, sum;
		int next[26], suff;
		TrieNode(){
			num = sum = 0;
			for(int i = 0; i < 26; i++) next[i] = -1;
		}
	};
	vector<TrieNode> trie;
	
	AhoCorasick(){
		init();
	}
	void init(){
		trie.clear();
		trie.push_back(TrieNode());
	}
	int seek(string &s)
	{
		int p = 0;
		for(int i = 0; i < s.size(); i++){
			int c = s[i]-'a';
			if(trie[p].next[c] == -1){
				trie.push_back(TrieNode());
				trie[p].next[c] = (int)trie.size()-1;
			}
			p = trie[p].next[c];
		}
		return p;
	}
	
	int trans(int v, int c)
	{
		if(trie[v].next[c] != -1) return trie[v].next[c];
		if(v == 0) return 0;
		return trans(trie[v].suff, c);
	}
	
	int addString(string &s)
	{
		int p = seek(s);
		return p;
	}
	
	void makeSuffixLink()
	{
		queue<int> Q;
		Q.push(0);
		trie[0].suff = 0;
		
		int v;
		while(Q.size()){
			v = Q.front();
			Q.pop();
			trie[v].sum = trie[v].num + trie[trie[v].suff].sum;
			for(int i = 0; i < 26; i++){
				int u = trie[v].next[i];
				if(u == -1) continue;
				trie[u].suff = trans(trie[v].suff, i);
				if(v == 0) trie[u].suff = 0;
				Q.push(u);
			}
		}
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

int n, m;
int p[300005];
AhoCorasick aho;
vector<int> G[2000005];
HLD hld;
SegTree seg(20);

int a[300005];
string str[300005];
multiset<int> S[300005];
int sid[300005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> str[i];
		p[i] = aho.addString(str[i]) + 1;
	}
	aho.makeSuffixLink();
	
	map<string, int> mp;
	for(int i = 1; i <= n; i++) mp[str[i]];
	int id = 1;
	for(auto &x : mp) x.second = id++;
	
	for(int i = 1; i <= n; i++){
		sid[i] = mp[str[i]];
		S[sid[i]].insert(0);
	}
	
	for(int i = 1; i < aho.trie.size(); i++){
		G[aho.trie[i].suff+1].push_back(i+1);
	}
	hld.init(G, (int)aho.trie.size());
	
	seg.init();
	vector<P> res;
	for(int i = 1; i <= n; i++){
		hld.getPath(p[i], p[i], res);
		seg.update(res[0].first, 0);
	}
	
	int t, x, y; string s;
	rep(q, 1, m){
		cin >> t;
		if(t == 1){
			cin >> x >> y;
			multiset<int> &cset = S[sid[x]];
			cset.erase(cset.lower_bound(a[x]));
			a[x] = y;
			cset.insert(a[x]);
			hld.getPath(p[x], p[x], res);
			seg.update(res[0].first, *cset.rbegin());
		}
		else{
			cin >> s;
			int ans = -1, v = 0;
			for(int i = 0; i < s.size(); i++){
				v = aho.trans(v, s[i]-'a');
				hld.getPath(v+1, 1, res);
				for(int j = 0; j < res.size(); j++){
					ans = max(ans, seg.query(res[j].first, res[j].second));
				}
			}
			cout << ans << "\n";
		}
	}
	flush(cout);
	
	return 0;
}