#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int> > a(n);
	vector<pair<int,int> > what;
	for(int i = 0; i < n; i++){
		int l;
		cin >> l;
		a[i].resize(l);
		for(int j = 0; j < l; j++) cin >> a[i][j];
		bool ok = true;
		for(int j = 0; j + 1 < l; j++){
			if(a[i][j] < a[i][j+1]) ok = false;
		}
		if(ok){
			what.push_back({a[i].front(), 0});
			what.push_back({a[i].back(), 1});
		}
	}
	sort(what.begin(), what.end());
	ll ans = 1ll * n * n;
	ll cur = 0;
	for(pair<int,int> v : what){
		if(v.second == 0){
			cur ++;
		} else {
			ans -= cur;
		}
	}
	cout << ans << '\n';
}