#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		x = abs(x);
		if(i & 1) x = -x;
		cout << x << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}