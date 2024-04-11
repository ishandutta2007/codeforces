#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int d = 0; d < n; d++){
		bool rainy = true;
		for(int j = d-x; j <= d + y; j++){
			if(j == d) continue;
			if(j < 0 || j >= n) continue;
			if(a[j] <= a[d]) rainy = false;
		}
		if(rainy){
			cout << d + 1 << '\n';
			return 0;
		}
	}
}