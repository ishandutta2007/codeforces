#include <bits/stdc++.h>
using namespace std;

void solve(){
	int a, b;
	cin >> a >> b;
	cout << min(min(a, b), (a + b) / 4) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}