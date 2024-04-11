#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	map<int,int> x;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		x[a]++;
	}
	for(int j = 0; j < n-1; j++){
		map<int,int> y;
		int prv = -1;
		for(auto [k, f] : x){
			if(f-1) y[0] += f-1;
			if(prv >= 0){
				y[k-prv] += 1;
			}
			prv = k;
		}
		x = y;
	}
	for(auto [k, f] : x){
		cout << k << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}