#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	vector<int> cur;
	for(int x : a){
		if(cur.empty()){
			cur.push_back(x);
		} else if(x > cur.front()){
			cur.resize(1);
		} else if(x > cur.back()){
		} else {
			cur.push_back(x);
		}
	}
	if(cur.size() == 1){
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}