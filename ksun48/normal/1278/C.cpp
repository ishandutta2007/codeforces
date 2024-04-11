#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for(int& x : a){
		cin >> x;
		if(x == 2) x = -1;
	}
	for(int& x : b){
		cin >> x;
		if(x == 2) x = -1;
	}
	reverse(b.begin(), b.end());
	map<int,int> am;
	am[0] = 0;
	int ac = 0;
	for(int i = 0; i < n; i++){
		ac += a[i];
		am[ac] = i+1;
	}
	int best = 0;
	int bc = 0;
	if(am.count(-bc)) best = am[-bc];
	for(int i = 0; i < n; i++){
		bc += b[i];
		if(am.count(-bc)) best = max(best, am[-bc] + i+1);
	}
	cout << 2*n-best << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}