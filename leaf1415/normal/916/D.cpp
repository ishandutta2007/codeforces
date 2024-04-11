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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
typedef pair<llint, string> R;
typedef pair<R, P> E;

// sum-query

struct PersistentSegTree{
	struct SegNode{
		int val;
		int left, right, parent;
		SegNode(int p, int x = 0){  //initial value
			left = right = -1;
			parent = p;
			val = x;
		}
	};
	
	int size;
	vector<int> root;
	vector<SegNode> seg;
	
	PersistentSegTree(int size){
		this->size = size;
		init();
	}
	
	void init()
	{
		seg.clear();
		seg.push_back(SegNode(-1));
		root.clear();
		root.push_back(0);
	}
	
	void check(int p){
		if(seg[p].left == -1){
			seg.push_back(SegNode(p));
			seg[p].left = (int)seg.size()-1;
		}
		if(seg[p].right == -1){
			seg.push_back(SegNode(p));
			seg[p].right = (int)seg.size()-1;
		}
	}
	
	int update(int t, int i, int val)
	{
		seg.push_back(SegNode(-1));
		root.push_back((int)seg.size()-1);
		
		int p = root[t], q = root.back(), l = 0, r = (1<<size)-1;
		while(l < r){
			check(p);
			if(i <= (l+r)/2){
				seg.push_back(SegNode(q));
				seg[q].left = (int)seg.size()-1;
				seg[q].right = seg[p].right;
				p = seg[p].left, r = (l+r)/2;
				q = seg[q].left;
			}
			else{
				seg.push_back(SegNode(q));
				seg[q].left = seg[p].left;
				seg[q].right = (int)seg.size()-1;
				p = seg[p].right, l = (l+r)/2+1;
				q = seg[q].right;
			}
		}
		seg[q].val = val;
		
		q = seg[q].parent;
		while(q != -1){
			seg[q].val = seg[seg[q].left].val + seg[seg[q].right].val;
			q = seg[q].parent;
		}
		return (int)root.size()-1;
	}
	int update(int i, int val)
	{
		update((int)root.size()-1, i, val);
	}
	
	int query(int t, int a, int b, int p, int l, int r)
	{
		if(b < l || r < a) return 0;
		if(a <= l && r <= b) return seg[p].val;
		
		check(p);
		int lval = query(t, a, b, seg[p].left, l, (l+r)/2);
		int rval = query(t, a, b, seg[p].right, (l+r)/2+1, r);
		return lval + rval;
	}
	int query(int t, int a, int b)
	{
		return query(t, a, b, root[t], 0, (1<<size)-1);
	}
};

ll Q;
map<string, ll> mp;
vector<E> vec;
PersistentSegTree seg(30), seg2(17);
ll t[100005];

int change(ll tm, ll id, ll x)
{
	ll f = seg2.query(tm, id, id);
	if(f > 0){
		seg2.update(tm, id, 0);
		tm = seg.update(tm, f, seg.query(tm, f, f)-1);
	}
	if(x > 0){
		seg2.update(tm, id, x);
		tm = seg.update(tm, x, seg.query(tm, x, x)+1);
	}
	return tm;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	
	ll id = 1;
	string type, s; ll x;
	rep(q, 1, Q){
		cin >> type;
		if(type == "set"){
			cin >> s >> x;
			if(mp.count(s) == 0) mp[s] = id++;
			t[q] = change(t[q-1], mp[s], x);
		}
		if(type == "remove"){
			cin >> s;
			if(mp.count(s) == 0) mp[s] = id++;
			t[q] = change(t[q-1], mp[s], 0);
		}
		if(type == "query"){
			cin >> s;
			if(mp.count(s) == 0) mp[s] = id++;
			t[q] = t[q-1];
			ll res = seg2.query(t[q], mp[s], mp[s]);
			if(res == 0) cout << -1 << endl;
			else cout << seg.query(t[q], 1, res-1) << endl;
		}
		if(type == "undo"){
			cin >> x;
			t[q] = t[q-(x+1)];
		}
	}
	
	return 0;
}