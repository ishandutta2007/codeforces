#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N;
	cin >> N;
	vector<int> X(N);
	vector<int> T(N);
	for(int& x : X) cin >> x;
	for(int& x : T) cin >> x;
	vector<int> a;
	for(int i = 0; i < N; i++){
		a.push_back(X[i] - T[i]);
		a.push_back(X[i] + T[i]);
	}
	sort(a.begin(), a.end());
	cout << fixed << setprecision(10);
	cout << (double(a.front() + a.back()) / 2.0) << '\n';
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}