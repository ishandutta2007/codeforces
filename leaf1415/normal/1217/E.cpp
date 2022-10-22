#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#define llint long long
#define inf 2000000005//000000000
 
using namespace std;
typedef pair<int, int> P;
 
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
		for(int i = 0; i < (1<<size); i++) seg[i+(1<<size)] = make_pair(inf, i);
		//for(int i = (1<<size)-1; i >= 1; i--) seg[i] = min(seg[i*2], seg[i*2+1]);
	}
	void check(){
		for(int i = (1<<size)-1; i >= 1; i--) seg[i] = min(seg[i*2], seg[i*2+1]);
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
		if(b < l || r < a) return make_pair(inf, inf);
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
 
int n, m;
llint a[200005];
SegTree seg[9];
 
int main(void)
{
	scanf("%d %d", &n, &m);
	int z;
	for(int i = 1; i <= n; i++){
		scanf("%d", &z);
		a[i] = z;
	}
	
	for(int i = 0; i < 9; i++){
		seg[i] = SegTree(18);
		seg[i].init();
	}
	
	for(int j = 1; j <= n; j++){
		llint v = a[j];
		for(int i = 0; i < 9; i++){
			if(v % 10 == 0);//seg[i].update(j, make_pair(inf, j));
			else seg[i].seg[j+(1<<18)] = make_pair(a[j], j);
			v /= 10;
		}
	}
	
	for(int i = 0; i < 9; i++) seg[i].check();
	
	int t, p, x, l, r;
	for(int q = 0; q < m; q++){
		scanf("%d", &t);
		if(t == 1){
			scanf("%d %d", &p, &x);
			llint v = x;
			for(int i = 0; i < 9; i++){
				if(v % 10 == 0) seg[i].update(p, make_pair(inf, p));
				else seg[i].update(p, make_pair(x, p));
				v /= 10;
			}
		}
		else{
			scanf("%d %d", &l, &r);
			int ans = inf;
			for(int i = 0; i < 9; i++){
				//cout << "*" << i << endl;
				P m = seg[i].query(l, r);
				if(m.first >= inf) continue;
				seg[i].update(m.second, make_pair(inf, m.second));
				P m2 = seg[i].query(l, r);
				seg[i].update(m.second, m);
				if(m2.first >= inf) continue;
				ans = min(ans, m.first+m2.first);
			}
			if(ans >= inf) ans = -1;
			printf("%d\n", ans);
		}
	}
	flush(cout);
	
	return 0;
}