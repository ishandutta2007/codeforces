#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	map<int, long long> a;
	int n;
	cin >> n;
	long long ans = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a[i-x] += x;
		ans = max(ans, a[i-x]);
	}
	cout << ans << '\n';
}