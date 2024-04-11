#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if(a.back() > b.front()){
		cout << -1 << '\n';
		return 0;
	}
	ll def = 0;
	for(int i = 0; i < n; i++) def += a[i];
	def *= m;
	for(int i = 1; i < m; i++){
		def += b[i] - a.back();
	}
	if(b[0] != a.back()){
		def += b[0] - a[n-2];
	}
	cout << def << '\n';
}