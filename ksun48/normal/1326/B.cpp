#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> b(n);
	for(int& x : b) cin >> x;
	int cmax = 0;
	for(int i = 0; i < n; i++){
		int a = b[i] + cmax;
		cout << a << ' ';
		cmax = max(cmax, a);
	}
	cout << '\n';
}