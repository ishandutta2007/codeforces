#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> b(n);
	vector<pair<int,int> > intervals(n);
	for(int& x : b) cin >> x;
	for(int i = 0; i < n; i++){
		int x = i+1;
		if(b[i] == 0){
			intervals[i] = {x+1, n};
		} else {
			intervals[i] = {x / (b[i]+1) + 1, x / b[i]};
		}
	}
	set<int> unused;
	for(int i = 1; i <= n; i++) unused.insert(i);
	vector<int> ord(n);
	for(int i = 0; i < n; i++){
		ord[i] = i;
	}
	sort(ord.begin(), ord.end(), [&](int x, int y){
		return intervals[x].second < intervals[y].second;
	});
	vector<int> a(n);
	for(int i : ord){
		auto [l, r] = intervals[i];
		int x = *unused.lower_bound(l);
		assert(x <= r);
		unused.erase(x);
		a[i] = x;
	}
	for(int i = 0; i < n; i++){
		cout << a[i] << " \n"[i == n-1];
	}
	}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}