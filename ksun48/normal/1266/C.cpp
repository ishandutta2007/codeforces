#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int r, c;
	cin >> r >> c;
	vector<int> x, y;
	if(r == 1 && c == 1){
		cout << 0 << '\n';
		return 0;
	}
	if(r == 1){
		x.push_back(1);
		for(int j = 2; j <= c+1; j++) y.push_back(j);
	} else {
		for(int j = 1; j <= c; j++) y.push_back(j);
		for(int j = c+1; j <= c+r; j++) x.push_back(j);
	}
	assert(r == (int)x.size() && c == (int)y.size());
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout << (x[i] * y[j] / __gcd(x[i], y[j])) << " \n"[j == c-1];
		}
	}
}