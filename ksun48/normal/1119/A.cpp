#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int ans = 0;
	if(a.front() != a.back()) ans = n-1;
	if(a.front() == a.back()){
		int z = n-1;
		while(a[z] == a[0]) z--;
		ans = max(ans, z);
		int y = 0;
		while(a[n-1] == a[y]) y++;
		ans = max(ans, n-1-y);
	}
	cout << ans << '\n';
}