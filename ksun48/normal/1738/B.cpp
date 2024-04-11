#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
void solve(){
	ll N, K;
	cin >> N >> K;
	vector<ll> S(N+1);
	for(int i = N-K+1; i <= N; i++){
		cin >> S[i];
	}
	if(K == 1){
		cout << "YES" << '\n';
		return;
	}
	int st = N - K + 1;
	if(st == 1) st = 0;
	for(int i = st; i + 2 <= N; i++){
		if(S[i+1] - S[i] > S[i+2] - S[i+1]){
			cout << "NO" << '\n';
			return;
		}
	}
	ll diff = S[st+1] - S[st];
	ll s0 = S[st] - st * diff;
	if(s0 > 0){
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}