#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> M;

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
			seg[i] = -inf;
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
			seg[i] = max(seg[i*2], seg[i*2+1]);
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
		seg[k] = max(seg[k*2], seg[k*2+1]);
	}
	void add(int a, int b, llint val){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val);
	}
 
	llint query(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return -inf;
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return max(lval, rval);
	}
	llint query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

llint n, m, p;
P a[200005], b[200005];
vector<M> vec;
vector<llint> comp;
LazySegTree seg(18);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> p;
	for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
	for(int i = 1; i <= m; i++) cin >> b[i].first >> b[i].second;
	sort(a+1, a+n+1), sort(b+1, b+m+1);
	
	llint x, y, z;
	for(int i = 1; i <= p; i++){
		cin >> x >> y >> z;
		//swap(y, x);
		x++, y++;
		vec.push_back(M(x, P(y, z)));
	}
	sort(vec.begin(), vec.end());
	
	seg.init();
	for(int i = 1; i <= m; i++) seg.update(i, -b[i].second);
	
	llint ans = -inf, p = 0;
	for(int i = 1; i <= n; i++){
		while(p < vec.size() && vec[p].first <= a[i].first){
			llint x = lower_bound(b+1, b+m+1, P(vec[p].second.first, -inf)) - b;
			seg.add(x, m, vec[p].second.second);
			p++;
		}
		ans = max(ans, seg.query(1, m) - a[i].second);
		
		//for(int i = 1; i <= m; i++) cout << seg.query(i, i) << " "; cout << endl;
	}
	cout << ans << endl;
	
	return 0;
}