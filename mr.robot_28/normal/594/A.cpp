#include<bits/stdc++.h>
 
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> x(n);
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	int ans = 1e9;
	for(int i = 0; i + (n - 2) / 2 + 1 < n; i++)
	{
		ans = min(ans, x[i + (n - 2) / 2 + 1] - x[i]);
	}
	cout << ans;
	return 0;
}