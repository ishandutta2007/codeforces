#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	map<int,int> x;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		x[abs(a)]++;
	}
	int res = 0;
	for(auto [r, f] : x){
		if(r == 0){
			res++;
		} else {
			res += min(2, f);
		}
	}
	cout << res << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}