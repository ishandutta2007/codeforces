#include <iostream>
#include <vector>
#define inf 1e9

using namespace std;

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
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = inf;
	}
	
	void update(int i, int val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = min(seg[i*2], seg[i*2+1]);
		}
	}

	int query(int a, int b, int k, int l, int r)
	{
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

int n, m, q;
int P[200005], a[200005];
int p[200005];
int nx[18][200005], r[200005];
SegTree seg(18);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++) cin >> P[i];
	for(int i = 1; i <= m; i++) cin >> a[i];
	
	for(int i = 1; i <= n-1; i++) p[P[i]] = P[i+1];
	p[P[n]] = P[1];
	
	for(int i = 1; i <= n; i++) r[i] = m+1;
	for(int i = m; i >= 1; i--){
		nx[0][i] = r[p[a[i]]];
		r[a[i]] = i;
	}
	nx[0][m+1] = m+1;
	
	for(int i = 1; i < 18; i++){
		for(int j = 1; j <= m+1; j++){
			nx[i][j] = nx[i-1][nx[i-1][j]];
		}
	}
	
	seg.init();
	for(int i = 1; i <= m; i++){
		int x = i;
		for(int j = 0; j < 18; j++){
			if((n-1) & (1<<j)) x = nx[j][x];
		}
		seg.update(i, x);
	}
	
	int l, r; string ans;
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		if(seg.query(l, r) <= r) ans += '1';
		else ans += '0';
	}
	cout << ans << endl;
	
	return 0;
}