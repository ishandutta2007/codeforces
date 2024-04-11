#include <bits/stdc++.h>
using namespace std;

void solve(){
	long long n, m;
	cin >> n >> m;
	cout << min(n-1, 2ll) * m << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}