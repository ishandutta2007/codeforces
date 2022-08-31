#include <bits/stdc++.h>
using namespace std;

void solve(){
	int a, b;
	cin >> a >> b;
	int d = int(a > 1) + int(b > 1);
	cout << d << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}