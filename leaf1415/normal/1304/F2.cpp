#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;

struct SegTree{
	int size;
	vector<llint> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = -inf;
	}
	
	void update(int i, llint val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = max(seg[i*2], seg[i*2+1]);
		}
	}

	llint query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return -inf;
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return max(lval, rval);
	}
	llint query(int a, int b)
	{
		if(a > b) return -inf;
		return query(a, b, 1, 0, (1<<size)-1);
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
		int k = 1, l = 0, r = (1<<size)-1;
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

llint n, m, k;
llint a[55][20005];
llint sum[55][20005];
llint dp[55][20005];
SegTree seg(15);
LazySegTree seg2(15);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			sum[i][j] = sum[i][j-1] + a[i][j];
		}
	}
	
	seg.init();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m-k+1; j++){
			dp[i][j] = -inf;
		}
	}
	for(int j = 1; j <= m-k+1; j++){
		dp[1][j] = (sum[1][j+k-1]-sum[1][j-1]) + (sum[2][j+k-1]-sum[2][j-1]);
		seg.update(j, dp[1][j]);
	}
	
	seg2.init();
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= k; j++){
			seg2.update(j, dp[i][j] - (sum[i+1][k]-sum[i+1][j-1]) );
		}
		for(int j = 1; j <= m-k+1; j++){
			llint x = (sum[i+1][j+k-1]-sum[i+1][j-1]) + (sum[i+2][j+k-1]-sum[i+2][j-1]);
			llint y = max(seg.query(1, j-k), seg.query(j+k, m-k+1));
			dp[i+1][j] = x + y;
			
			llint L = max(j-k+1, 1LL), R = min(j+k-1, m-k+1);
			dp[i+1][j] = max(dp[i+1][j], seg2.query(L, R) + x);
			
			//for(int l = 1; l <= m-k+1; l++) cout << seg2.query(l, l) << " "; cout << endl;
			
			seg2.add(L, j, a[i+1][j]);
			seg2.add(j+1, R, -a[i+1][j+k]);
			seg2.update(j+k, dp[i][j+k] - a[i+1][j+k]);
		}
		for(int j = 1; j <= m-k+1; j++) seg.update(j, dp[i+1][j]);
		//cout << endl;
	}
	
	/*for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m-k+1; j++){
			cout << (sum[i][j+k-1]-sum[i][j-1]) + (sum[i+1][j+k-1]-sum[i+1][j-1]) << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m-k+1; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	cout << seg.query(1, m-k+1) << endl;
	
	return 0;
}