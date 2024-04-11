#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<vector<int> > ops;
	auto do_op = [&](vector<int> r){
		vector<int> s;
		for(int x : r) if(x != 0) s.push_back(x);
		ops.push_back(s);
		int cur = 0;
		for(int x : s){
			reverse(a.begin() + cur, a.begin() + cur + x);
			cur += x;
		}
		assert(cur == n);
		reverse(a.begin(), a.end());
	};
	for(int j = 2; j <= n; j++){
		int p1 = 0;
		while(a[p1] != 1) p1++;
		int dir = 1;
		if(p1 > 0 && a[p1-1] == 2) dir = -1;

		int pj = 0;
		while(a[pj] != j) pj++;
		vector<int> op;
		if(dir == 1){
			if(pj > p1){
				// 12345   pj
				for(int f = 0; f < p1 + j-1; f++) op.push_back(1);
				op.push_back((pj+1) - (p1+j-1));
				op.push_back(n - (pj+1));
			} else {
				// pj 12345  
				for(int f = 0; f < pj+1; f++) op.push_back(1);
				op.push_back((p1+j-1) - (pj+1));
				op.push_back(n - (p1+j-1));
			}
		} else {
			// 54321 pj
			if(pj > p1){
				op.push_back((p1-j+2));
				op.push_back(pj - (p1-j+2));
				for(int f = 0; f < n - pj; f++) op.push_back(1);
			} else {
				// pj 54321
				op.push_back(pj);
				op.push_back((p1-j+2)-pj);
				for(int f = 0; f < n - (p1-j+2); f++) op.push_back(1);
			}
		}
		do_op(op);
	}
	if(a[0] != 1){
		do_op(vector<int>(n, 1));
	}
	for(int i = 0; i < n; i++) assert(a[i] == i+1);
	cout << ops.size() << '\n';
	for(vector<int> s : ops){
		cout << s.size();
		for(int b : s){
			cout << ' ' << b;
		}
		cout << '\n';
	}
}