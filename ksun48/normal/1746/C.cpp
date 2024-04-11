#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N;
	cin >> N;
	vector<int> A(N);
	for(int& x : A) cin >> x;
	vector<int> loc(N);
	for(int i = 0; i < N; i++){
		loc[N-A[i]] = i;
	}
	for(int i = 0; i < N; i++){
		cout << (loc[i] + 1) << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}