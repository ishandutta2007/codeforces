#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int& x : a) cin >> x;
	for(int& x : b) cin >> x;
	using B = bitset<11111>;
	B sum;
	sum[0] = 1;
	for(int i = 0; i < n; i++){
		sum = (sum << a[i]) | (sum << b[i]);
	}
	int tsq = 0;
	int tsum = 0;
	for(int i = 0; i < n; i++){
		tsq += a[i] * a[i];
		tsq += b[i] * b[i];
		tsum += a[i];
		tsum += b[i];
	}
	int ans = 1e9;
	for(int i = 0; i < sum.size(); i++){
		if(sum[i]){
			ans = min(ans, i * i + (tsum - i) * (tsum - i));
		}
	}
	int fans = ans + (n-2) * tsq;
	cout << fans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}