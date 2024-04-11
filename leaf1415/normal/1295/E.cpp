#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;

// range-add, range-min query
 
struct SegTree{
	int size;
	vector<llint> seg, delay;
	
	SegTree(){}
	SegTree(int size){
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

llint n;
llint p[200005], pinv[200005];
llint a[200005], c[200005];
SegTree seg(18);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 1; i <= n; i++) pinv[p[i]] = i;
	for(int i = 1; i <= n; i++) c[i] = a[pinv[i]];
	
	seg.init();
	for(int i = 0; i <= n; i++) seg.update(i, 0);
	for(int i = 1; i <= n; i++) seg.add(i, n, c[i]);
	
	//for(int i = 1; i <= n; i++) cout << c[i] << " "; cout << endl;
	
	llint ans = inf, usum = 0;
	for(int i = 1; i < n; i++){
		usum += c[p[i]];
		seg.add(p[i], n, -2*c[p[i]]);
		ans = min(ans, seg.query(0, n) + usum);
		//cout<< usum << endl;
		//for(int j = 0; j <= n; j++) cout << seg.query(j, j) << " "; cout << endl;
	}
	cout << ans << endl;
	
	return 0;
}