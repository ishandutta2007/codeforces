#include <bits/stdc++.h>
using namespace std;

void solve(){
	int a, b;
	cin >> a >> b;
	cout << (b - (a % b)) % b << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}