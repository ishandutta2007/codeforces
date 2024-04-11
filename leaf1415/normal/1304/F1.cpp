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

llint n, m, k;
llint a[55][20005];
llint sum[55][20005];
llint dp[55][20005];
SegTree seg(15);

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
	seg.update(1, 0);
	
	for(int i = 0; i <= n; i++){
		for(int j = 1; j <= m-k+1; j++){
			dp[i][j] = -inf;
		}
	}
	dp[0][1] = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= m-k+1; j++){
			llint x = (sum[i+1][j+k-1]-sum[i+1][j-1]) + (sum[i+2][j+k-1]-sum[i+2][j-1]);
			llint y = max(seg.query(1, j-k), seg.query(j+k, m-k+1));
			dp[i+1][j] = x + y;
			for(int l = j-k+1; l <= j+k-1; l++){
				if(l < 1 || l > m-k+1) continue;
				llint L = max(l, j), R = min(l+k-1, j+k-1);
				llint z = x;
				if(i >= 1) z -= (sum[i+1][R] - sum[i+1][L-1]);
				dp[i+1][j] = max(dp[i+1][j], dp[i][l] + z);
			}
		}
		for(int j = 1; j <= m-k+1; j++) seg.update(j, dp[i+1][j]);
	}
	
	/*for(int i = 0; i <= n; i++){
		for(int j = 1; j <= m-k+1; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	cout << seg.query(1, m-k+1) << endl;
	
	return 0;
}