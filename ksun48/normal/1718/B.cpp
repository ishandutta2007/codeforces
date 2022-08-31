#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
ll MAXN = 100 * ll(1e9) * 4;

void solve(){
	vector<ll> fib = {1, 1};
	while(fib.back() < MAXN){
		fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
	}
	int K;
	cin >> K;
	vector<ll> A(K);
	for(ll& x : A) cin >> x;
	ll sum = 0;
	for(ll x : A) sum += x;
	int l = 0;
	ll jsum = 0;
	while(jsum < sum){
		jsum += fib[l];
		l++;
	}
	if(jsum != sum){
		cout << "NO" << '\n';
		return;
	}
	int F = (int)fib.size();
	vector<int> cnt(F);
	vector<int> need(F, 0);
	for(int i = 0; i < l; i++){
		need[i]++;
	}
	need[0] = 0;
	for(int i = 0; i < K; i++){
		A[i]--;
		cnt.assign(F, 0);
		for(int j = 0; j < K; j++){
			ll x = A[j];
			while(x){
				int r = upper_bound(fib.begin(), fib.end(), x) - fib.begin();
				r--;
				x -= fib[r];
				if(cnt[r]) goto fail;
				if(i == j && r <= 1) goto fail;
				cnt[r]++;
			}
		}
		if(cnt == need){
			cout << "YES" << '\n';
			return;
		}
		fail:; 
		A[i]++;
	}
	cout << "NO" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}