#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <stack>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

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
			seg[i] = 0;
			delay[i] = 0;
		}
	}
	
	void eval(int l, int r, int k)
	{
		if(delay[k]){
			seg[k] += delay[k] * (r-l+1);  //
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
			seg[i] = (seg[i*2] + seg[i*2+1]);
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
		seg[k] = (seg[k*2] + seg[k*2+1]);
	}
	void add(int a, int b, llint val){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val);
	}
 
	llint query(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return 0;
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return (lval + rval);
	}
	llint query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

llint n;
P p[200005];
LazySegTree seg(18), seg2(18);
vector<llint> comp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> p[i].first;
	for(int i = 1; i <= n; i++) cin >> p[i].second;
	sort(p+1, p+n+1);
	
	for(int i = 1; i <= n; i++) comp.push_back(p[i].second);
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for(int i = 1; i <= n; i++) p[i].second = lower_bound(comp.begin(), comp.end(), p[i].second) - comp.begin();
	
	seg.init();
	seg2.init();
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		ans += -seg.query(0, p[i].second) + seg2.query(0, p[i].second) * p[i].first;
		seg.add(p[i].second, p[i].second, p[i].first);
		seg2.add(p[i].second, p[i].second, 1);
	}
	cout << ans << endl;
	
	return 0;
}