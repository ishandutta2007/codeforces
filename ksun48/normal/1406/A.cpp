#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	multiset<int> r;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		r.insert(a);
	}
	int ans = 0;
	for(int j = 0; j < 2; j++){
		int cur = 0;
		while(r.count(cur)){
			r.erase(r.find(cur));
			cur++;
		}
		ans += cur;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}