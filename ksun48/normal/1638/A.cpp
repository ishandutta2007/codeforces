#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	for(int i = 0; i < n; i++){
		int mv = i;
		for(int j = i; j < n; j++){
			if(a[j] < a[mv]) mv = j;
		}
		if(mv != i){
			reverse(a.begin() + i, a.begin() + mv + 1);
			break;
		}
	}
	for(int i = 0; i < n; i++){
		cout << a[i] << " \n"[i == n-1];
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}