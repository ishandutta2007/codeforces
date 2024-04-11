#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

// range-add, range-min query

struct SegTree{
	int size;
	vector<P> seg;
	vector<llint> delay;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
		delay.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++){
			seg[i] = make_pair(-inf, -inf);
			delay[i] = 0;
		}
	}
	
	void eval(int l, int r, int k)
	{
		if(delay[k]){
			seg[k].first += delay[k];
			if(l < r){
				delay[k*2] += delay[k];
				delay[k*2+1] += delay[k];
			}
			delay[k] = 0;
		}
	}
	
	void update(int i, P val)
	{
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

	P query(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return make_pair(-inf, -inf);
		if(a <= l && r <= b) return seg[k];
		P lval = query(a, b, k*2, l, (l+r)/2);
		P rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return max(lval, rval);
	}
	P query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

llint n;
llint x[500005], y[500005], c[500005];
vector<llint> comp, compX;
vector<llint> vec[500005];
SegTree seg(19);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i] >> c[i];
		if(x[i] > y[i]) swap(x[i], y[i]);
	}
	
	for(int i = 1; i <= n; i++) comp.push_back(y[i]);
	sort(comp.begin(), comp.end()); 
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for(int i = 1; i <= n; i++){
		y[i] = lower_bound(comp.begin(), comp.end(), y[i]) - comp.begin();
	}
	int N = comp.size();
	
	for(int i = 1; i <= n; i++) compX.push_back(x[i]);
	sort(compX.begin(), compX.end()); 
	compX.erase(unique(compX.begin(), compX.end()), compX.end());
	for(int i = 1; i <= n; i++){
		x[i] = lower_bound(compX.begin(), compX.end(), x[i]) - compX.begin();
		vec[x[i]].push_back(i);
	}
	int X = compX.size();
	
	//for(int i = 0; i < N; i++) cout<< comp[i] << " "; cout << endl;
	
	seg.init();
	for(int i = 0; i < N; i++) seg.update(i, make_pair(-comp[i], i));
	
	llint ans = 0, max_l = 1000000007, max_r = 1000000007;
	for(int i = X-1; i >= 0; i--){
		for(int j = 0; j < vec[i].size(); j++){
			int id = vec[i][j];
			seg.add(y[id], N-1, c[id]);
		}
		llint l = lower_bound(comp.begin(), comp.end(), compX[i]) - comp.begin();
		P res = seg.query(l, N-1);
		llint tmp = res.first + compX[i];
		//for(int j = 0; j < N; j++) cout << seg.query(j, j).first << " "; cout << endl;
		//cout << res.first << " " << res.second << endl;
		if(tmp > ans) ans = tmp, max_l = compX[i], max_r = comp[res.second];
	}
	cout << ans << endl;
	cout << max_l << " " << max_l << " " << max_r << " " << max_r << endl;
	
	return 0;
}