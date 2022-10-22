#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<string, int> P;

// range-add, range-min query
 
struct SegTree{
	int size;
	vector<llint> seg, seg2, delay;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
		seg2.resize(1<<(size+1));
		delay.resize(1<<(size+1));
	}
	
	void init(int x)
	{
		for(int i = (1<<size); i < (1<<(size+1)); i++){
			if(i < (1<<size)+x) seg[i] = seg2[i] = 0;
			else seg[i] = inf, seg2[i] = -inf;
		}
		for(int i = 1; i < (1<<size); i++){
			seg[i] = min(seg[i*2], seg[i*2+1]);
			seg2[i] = max(seg2[i*2], seg2[i*2+1]);
		}
	}
	
	void eval(int l, int r, int k)
	{
		if(delay[k]){
			seg[k] += delay[k];  //
			seg2[k] += delay[k];  //
			if(l < r){
				delay[k*2] += delay[k];
				delay[k*2+1] += delay[k];
			}
			delay[k] = 0;
		}
	}
	
	void update(int i, llint val)
	{
		i += (1 << size);
		seg[i] = seg2[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = min(seg[i*2], seg[i*2+1]);
			seg2[i] = max(seg2[i*2], seg2[i*2+1]);
			
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
		seg[k] = min(seg[k*2], seg[k*2+1]);
		seg2[k] = max(seg2[k*2], seg2[k*2+1]);
	}
	void add(int a, int b, llint val){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val);
	}
 
	llint query(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
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
	
	llint query2(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return -inf;
		if(a <= l && r <= b) return seg2[k];
		llint lval = query2(a, b, k*2, l, (l+r)/2);
		llint rval = query2(a, b, k*2+1, (l+r)/2+1, r);
		return max(lval, rval);
	}
	llint query2(int a, int b)
	{
		return query2(a, b, 1, 0, (1<<size)-1);
	}
};

int n;
char c[1000005];
string s, S;
SegTree seg(19);
vector<llint> comp;

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	scanf("%d", &n);
	scanf("%s", c);
	
	s = string(c);
	
	int cur = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'L') cur = max(cur-1, 0);
		if(s[i] == 'R') cur++;
		if(s[i] == '(' || s[i] == ')') comp.push_back(cur);
	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	int N = comp.size();
	
	if(N == 0){
		for(int i = 0; i < n; i++) printf("0 ");
		printf("\n");
		return 0;
	}
	
	S = " ";
	seg.init(N), cur = 0;
	int ans = 0;
	for(int i = 0; i < s.size(); i++){
		//cout << i << " " << cur << endl;
		if(s[i] == 'L') cur = max(cur-1, 0);
		else if(s[i] == 'R'){
			cur++;
			if((llint)S.size() <= cur) S += ' ';
		}
		else{
			int p = lower_bound(comp.begin(), comp.end(), cur) - comp.begin();
			if(S[cur] == '(') seg.add(p, N-1, -1);
			if(S[cur] == ')') seg.add(p, N-1, 1);
			if(s[i] == '(') seg.add(p, N-1, 1);
			if(s[i] == ')') seg.add(p, N-1, -1);
			S[cur] = s[i];
			//for(int j = 0; j < N-1; j++) cout << seg.query(j, j) << " "; cout << endl;
			//cout << endl;
			if(seg.query(0, N-1) < 0 || seg.query(N-1, N-1) != 0) ans = -1;
			else ans = seg.query2(0, N-1);
		}
		printf("%d ", ans);
	}
	printf("\n");
	
	return 0;
}