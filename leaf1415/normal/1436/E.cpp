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
#define inf 1e9
#define mod 1000000007

using namespace std;
typedef pair<int, int> P;

// range-add, range-min query
 
struct LazySegTree{
	int size;
	vector<int> seg, delay;
	
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
			delay[i] = inf;
		}
	}
	
	void eval(int l, int r, int k)
	{
		if(delay[k] < inf/2){
			chmin(seg[k], delay[k]);  //
			if(l < r){
				chmin(delay[k*2], delay[k]);
				chmin(delay[k*2+1], delay[k]);
			}
			delay[k] = inf;
		}
	}
	
	
	void add(int a, int b, int k, int l, int r, int val)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			chmin(delay[k], val);
			eval(l, r, k);
			return;
		}
		add(a, b, k*2, l, (l+r)/2, val);
		add(a, b, k*2+1, (l+r)/2+1, r, val);
		seg[k] = min(seg[k*2], seg[k*2+1]);
	}
	void add(int a, int b, int val){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val);
	}
 
	int query(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return inf;
		if(a <= l && r <= b) return seg[k];
		int lval = query(a, b, k*2, l, (l+r)/2);
		int rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return min(lval, rval);
	}
	int query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

int n;
int a[100005];
vector<int> vec[100005];
LazySegTree seg(17);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	int mx = -inf, mn = inf;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		chmax(mx, a[i]);
		chmin(mn, a[i]);
		vec[a[i]].push_back(i);
	}
	if(mn >= 2){
		cout << 2 << endl;
		return 0;
	}
	if(mx <= 1){
		cout << 1 << endl;
		return 0;
	}
	
	/*set<int> S;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i > j) continue;
			set<int> T;
			for(int k = i; k <= j; k++){
				T.insert(a[k]);
			}
			int g = 1;
			while(T.count(g)) g++;
			S.insert(g);
		}
	}
	int g = 1;
	while(S.count(g)) g++;*/
	
	for(int i = 1; i <= n+1; i++){
		vec[i].insert(vec[i].begin(), 0);
		vec[i].push_back(n+1);
	}
	
	seg.init();
	int ans = 1;
	for(int i = 1; i <= n+1; i++){
		if(i >= 2){
			bool flag = false;
			for(int j = 1; j < (int)vec[i].size(); j++){
				if(seg.query(vec[i][j], vec[i][j]) > vec[i][j-1]){
					flag = true;
					break;
				}
			}
			if(flag) ans = i;
			else break;
		}
		for(int j = 1; j < vec[i].size(); j++){
			seg.add(vec[i][j-1], vec[i][j]-1, vec[i][j-1]);
			if(j == (int)vec[i].size()-1) seg.add(vec[i][j-1], vec[i][j], vec[i][j-1]);
		}
		//for(int j = 1; j <= n; j++) cout << seg.query(j, j) << " "; cout << endl;
	}
	cout << ans+1 << endl;
	
	return 0;
}