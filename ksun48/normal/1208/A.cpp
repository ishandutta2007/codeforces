#include <bits/stdc++.h>
using namespace std;

void solve(){
	int a, b, n;
	cin >> a >> b >> n;
	vector<int> r(24);
	r[0] = a;
	r[1] = b;
	for(int i = 2; i < (int)r.size(); i++){
		r[i] = r[i-1] ^ r[i-2];
	}
	cout << r[n % 24] << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		solve();
	}
}