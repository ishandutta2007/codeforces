#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	if(n & 1){
		cout << "NO" << '\n';
		return 0;
	}
	int vx = x[0] + x[n/2];
	int vy = y[0] + y[n/2];
	for(int i = 0; i < n/2; i++){
		if(x[i] + x[i + n/2] != vx){
			cout << "NO" << '\n';
			return 0;
		}
		if(y[i] + y[i + n/2] != vy){
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
	return 0;
}