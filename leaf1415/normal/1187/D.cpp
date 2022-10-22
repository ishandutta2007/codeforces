#include <iostream>
#include <string>
#include <vector>
#include <utility>
#define llint long long
#define inf 1e9

using namespace std;
typedef pair<llint, llint> P;

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

llint Q, n;
llint a[300005], b[300005];
vector<int> vec[300005];
llint pos[300005];
SegTree seg(19);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	seg.init();
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) cin >> b[i];
		
		for(int i = 1; i <= n; i++) vec[i].clear(), pos[i] = 0;
		for(int i = 1; i <= n; i++) vec[a[i]].push_back(i);
		
		//seg.init();
		for(int i = 1; i <= n; i++) seg.update(i, a[i]);
		
		int p;
		for(int i = 1; i <= n; i++){
			if(pos[b[i]] >= vec[b[i]].size()){
				cout << "NO" << "\n";
				goto end;
			}
			p = vec[b[i]][pos[b[i]]];
			if(seg.query(1, p) < b[i]){
				cout << "NO" << "\n";
				goto end;
			}
			seg.update(p, inf);
			pos[b[i]]++;
		}
		cout << "YES" << "\n";
		end:;
	}
	flush(cout);
	
	return 0;
}