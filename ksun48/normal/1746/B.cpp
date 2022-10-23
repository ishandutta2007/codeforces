#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N;
	cin >> N;
	vector<int> A(N);
	for(int& x : A) cin >> x;
	vector<int> p1(N+1, 0);
	vector<int> s0(N+1, 0);
	for(int i = 0; i < N; i++){
		p1[i+1] = p1[i] + (A[i] == 1);
	}
	for(int i = N-1; i >= 0; i--){
		s0[i] = s0[i+1] + (A[i] == 0);
	}
	int ans = 0;
	for(int i = 0; i <= N; i++){
		ans = max(ans, min(p1[i], s0[i]));
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}