#include <bits/stdc++.h>
using namespace std;
mt19937 mt;

void solve(){
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int j = 0; j < 60; j++){
		shuffle(a.begin(), a.end(), mt);
		int cur = 0;
		bool works = true;
		for(int b : a){
			cur += b;
			if(cur == x) works = false;
		}
		if(works){
			cout << "YES" << '\n';
			for(int b : a){
				cout << b << ' ';
			}
			cout << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    mt = mt19937(chrono::steady_clock::now().time_since_epoch().count());
    int T;
    cin >> T;
    while(T--) solve();
}