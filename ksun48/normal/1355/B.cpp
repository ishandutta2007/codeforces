#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> e(n);
	for(int i = 0; i < n; i++) cin >> e[i];
	sort(e.begin(), e.end());
	int ans = 0;
	int last = -1;
	for(int i = 0; i < n; i++){
		if(i - last >= e[i]){
			ans++;
			last = i;
		}
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}