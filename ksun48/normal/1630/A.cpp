#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	int k;
	cin >> k;
	if(n == 4 && k == 3){
		cout << -1 << '\n';
		return;
	}
	vector<int> p(n/2, -1);
	vector<int> q(n/2, -1);
	for(int i = 0; i < n/2; i++){
		p[i] = i;
		q[i] = n-1-i;
	}
	if(k == n-1){
		p[0] = 0;
		q[0] = n-3;
		p[1] = 1;
		q[1] = 3;
		p[2] = 2;
		q[2] = n-4;
		p[3] = n-2;
		q[3] = n-1;
	} else if(k > 0){
		q[0] = n-1-k;
		int f = min(k, n-1-k);
		p[f] = k;
		q[f] = n-1;
	}
	int and_sum = 0;
	for(int i = 0; i < (n/2); i++){
		and_sum += (p[i] & q[i]);
		cout << p[i] << ' ' << q[i] << '\n';
	}
	assert(and_sum == k);
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}