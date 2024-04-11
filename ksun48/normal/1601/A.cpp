#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> freq(30);
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		for(int j = 0; j < 30; j++){
			if((1 << j) & a) freq[j]++;
		}
	}
	int g = 0;
	for(int x : freq){
		g = gcd(g, x);
	}
	for(int i = 1; i <= n; i++){
		if(g % i == 0){
			cout << i << ' ';
		}
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}