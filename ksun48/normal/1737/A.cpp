#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N, K;
	cin >> N >> K;
	string S;
	cin >> S;
	vector<int> A(26);
	for(char c : S) A[c-'a']++;
	string ans;
	for(int i = 0; i < K; i++){
		int r = 0;
		while(A[r] && r < N/K){
			A[r]--;
			r++;
		}
		ans += ('a' + r);
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}