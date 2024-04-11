#include <iostream>
#include <vector>
#define llint long long

using namespace std;

struct SegTree{
	int size;
	vector<llint> seg, delay, flag;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
		delay.resize(1<<(size+1));
		flag.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++){
			seg[i] = 0;
			delay[i] = 0;
			flag[i] = 0;
		}
	}
	
	void eval(int l, int r, int k)
	{
		if(flag[k]){
			seg[k] = delay[k] * (r-l+1);
			if(l < r){
				flag[k*2] = 1, delay[k*2] = delay[k];
				flag[k*2+1] = 1, delay[k*2+1] = delay[k];
			}
			flag[k] = 0;
		}
	}
	
	void update(int i, llint val)
	{
		query(i, i);
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = seg[i*2] + seg[i*2+1];
		}
	}
	
	void add(int a, int b, int k, int l, int r, llint val)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			flag[k] = true;
			delay[k] = val;
			eval(l, r, k);
			return;
		}
		add(a, b, k*2, l, (l+r)/2, val);
		add(a, b, k*2+1, (l+r)/2+1, r, val);
		seg[k] = seg[k*2] + seg[k*2+1];
	}
	void add(int a, int b, llint val){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val);
	}

	llint query(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return 0;
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return lval + rval;
	}
	llint query(int a, int b)
	{
		if(a > b) return 0;
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

llint n;
llint a[100005];
llint k[100005], sumk[100005];
llint Q;
SegTree seg(17), seg2(17);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 2; i <= n; i++) cin >> k[i];
	for(int i = 1; i <= n; i++) sumk[i] = sumk[i-1] + k[i];
	
	seg.init(), seg2.init();
	for(int i = 1; i <= n; i++) seg.update(i, a[i] - sumk[i]);
	for(int i = 1; i <= n; i++) seg2.update(i, sumk[i]);
	
	cin >> Q;
	char c; llint l, r, i, x;
	for(int q = 0; q < Q; q++){
		cin >> c;
		if(c == 's'){
			cin >> l >> r;
			llint ans = seg.query(l, r) + seg2.query(l, r);
			cout << ans << endl;
		}
		else{
			cin >> i >> x;
			llint val = seg.query(i, i) + x;
			seg.update(i, val);
			
			llint ub = n+1, lb = i, mid;
			while(ub-lb>1){
				mid = (ub+lb)/2;
				if(seg.query(mid, mid) < val) lb = mid;
				else ub = mid;
			}
			seg.add(i+1, lb, val);
		}
	}
	
	return 0;
}