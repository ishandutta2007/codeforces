#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int res = 1 % m;
	vector<int> a;
	for(int i = 0; i < n; i++){
		int b;
		cin >> b;
		for(int x : a) res = (res * (abs(b - x) % m)) % m;
		a.push_back(b);
		if(res == 0) break;
	}
	cout << res << '\n';
}