#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	cout << 2 << '\n';
	for(int i = 1; i <= n; i += 2){
		for(int b = i; b <= n; b *= 2){
			cout << b << ' ';
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