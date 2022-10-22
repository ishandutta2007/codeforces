#include <iostream>
#include <vector>
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

llint n, Q;
bool used[2][100005];
llint cover[2][100005];
llint val[100005];
SegTree seg(17);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	seg.init();
	for(int i = 1; i <= n; i++) seg.update(i, 0);
	
	llint x, y;
	for(int i = 1; i <= Q; i++){
		cin >> x >> y;
		x--;
		llint add;
		if(used[x][y]) add = -1;
		else add = 1;
		if(x == 0) cover[x][y] += add;
		else{
			for(int i = -1; i <= 1; i++) cover[x][y+i] += add;
		}
		for(int i = -1; i <= 1; i++){
			val[y+i] = 0;
			if(cover[0][y+i] > 0) val[y+i]--;
			if(cover[1][y+i] > 0) val[y+i]--;
			seg.update(y+i, val[y+i]);
		}
		//for(int i = 1;i <= n; i++) cout << val[i] << " "; cout << endl;
		used[x][y] = !used[x][y];
		if(seg.query(1, n) <= -2) cout << "No" << "\n";
		else cout << "Yes" << "\n";
	}
	flush(cout);
	
	return 0;
}