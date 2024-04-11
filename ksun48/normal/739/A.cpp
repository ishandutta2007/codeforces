#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, m;
	cin >> n >> m;
	int ans = 1e9;
	for(int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		ans = min(ans,r-l+1);
	}
	cout << ans << endl;
	for(int i = 0; i < n; i++){
		cout << (i % ans) << " ";
	}
	cout << endl;
}