#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int L, R;
	cin >> L >> R;
	vector<vector<int> > e;
	const int F = 22;
	for(int i = 0; i < F; i++){
		for(int j = 0; j < i; j++){
			e.push_back({j, i, (1 << max(j-1, 0))});
		}
	}
	int sz = R-L+1;
	e.push_back({0, F, 1});
	sz--;
	int cur = 2;
	for(int B = 0; B < F-2; B++){
		if(sz & (1 << B)){
			e.push_back({B+1, F, cur-1});
			cur += (1 << B);
		}
	}
	int n = F+1;
	if(L > 1){
		e.push_back({F, F+1, L-1});
		n++;
	}
	cout << "YES" << '\n';
	cout << n << ' ' << e.size() << '\n';
	for(vector<int> x : e){
		cout << (x[0] + 1) << ' ' << (x[1] + 1) << ' ' << x[2] << '\n';
	}
}