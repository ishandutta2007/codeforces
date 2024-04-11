#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int& x : a) cin >> x;
	for(int& x : b) cin >> x;
	for(int& x : a) while(x % 2 == 0) x /= 2;
	for(int& x : b) while(x % 2 == 0) x /= 2;
	map<int,int> freq;
	for(int x : a){
		while(x){
			freq[x] -= 1;
			x /= 2;
		}
	}
	for(int x : b){
		while(x){
			freq[x] += 1;
			x /= 2;
		}
	}
	bool works = true;
	for(auto [z, f] : freq){
		if(f < 0) works = false;
	}
	if(works){
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