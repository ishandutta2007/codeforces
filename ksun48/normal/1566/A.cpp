#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, s;
	cin >> n >> s;
	int k = (n + 2) / 2;
	cout << (s / k) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}