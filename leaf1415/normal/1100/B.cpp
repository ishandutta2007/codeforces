#include <iostream>
#include <vector>
using namespace std;
#define inf 1e9

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

int n, m;
int a[100005];
SegTree seg(17);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= m; i++) cin >> a[i];
	
	seg.init();
	for(int i = 1; i <= n; i++) seg.update(i, 0);
	
	int cnt = 1;
	for(int i = 1; i <= m; i++){
		seg.update(a[i], seg.query(a[i], a[i])+1);
		if(seg.query(1, n) >= cnt){
			cnt++;
			cout << "1";
		}
		else cout << "0";
	}
	cout << endl;
	
	return 0;
}