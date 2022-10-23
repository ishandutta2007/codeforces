#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	for(int& x : A) cin >> x;
	int D = N - 1;
	D %= (K-1);
	if(A == vector<int>(N, 0)){
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}