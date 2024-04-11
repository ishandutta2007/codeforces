#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

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
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = inf;
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

	llint query(int a, int b, int k, int l, int r)
	{
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
llint a[100005], b[100005];
SegTree seg(18), seg2(19);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	llint mx = -inf, mn = inf;
	for(int i = 0; i < n; i++){
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	if(mn >= (mx+1)/2){
		for(int i = 0; i < n; i++) cout << -1 << " "; cout << endl;
		return 0;
	}
	
	seg.init();
	for(int i = 0; i < 2*n; i++) seg.update(i, a[i%n]);
	
	for(int i = 0; i < n; i++){
		llint ub = 2*n+1, lb = i, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			//cout << i << " " << mid <<  " " << seg.query(i, mid) << " " << (a[i]+1)/2 << endl;
			if(seg.query(i, mid) >= (a[i]+1)/2) lb = mid;
			else ub = mid;
		}
		//cout << lb << endl;
		if(lb >= 2*n) b[i] = 10*n;
		else b[i] = lb - i;
	}
	
	//for(int i = 0; i < n; i++) cout << b[i] << " "; cout << endl;
	
	seg2.init();
	for(int i = 0; i < 3*n; i++){
		seg2.update(i, i + b[i%n]);
	}
	for(int i = 0; i < n; i++){
		cout << seg2.query(i, 3*n) - i + 1 << " ";
	}
	cout << endl;

	return 0;
}