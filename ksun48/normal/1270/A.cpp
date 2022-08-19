#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	vector<int> a(k1), b(k2);
	for(int i = 0; i < k1; i++) cin >> a[i];
	for(int i = 0; i < k2; i++) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if(a.back() > b.back()){
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}