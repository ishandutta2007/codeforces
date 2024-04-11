#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

struct SegTree{
	int size;
	vector<P> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = P(inf, inf);
	}
	
	void update(int i, P val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = min(seg[i*2], seg[i*2+1]);
		}
	}

	P query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return P(inf, inf);
		if(a <= l && r <= b) return seg[k];
		P lval = query(a, b, k*2, l, (l+r)/2);
		P rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return min(lval, rval);
	}
	P query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

llint Q, x;
SegTree seg(19);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q >> x;
	
	seg.init();
	for(int i = 0; i < x; i++) seg.update(i, P(0, i));
	
	llint y;
	for(int q = 0; q < Q; q++){
		cin >> y;
		llint p = y%x;
		seg.update(p, P(seg.query(p, p).first+1, p));
		P res = seg.query(0, x-1);
		//cout << res.first << " " << res.second << endl;
		cout << res.first * x + res.second << "\n";
	}
	flush(cout);
	
	return 0;
}