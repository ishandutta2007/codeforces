#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> cnt(2);
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		cnt[a & 1]++;
	}
	cout << min(cnt[0], cnt[1]) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}