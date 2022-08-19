#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	set<int> r;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		a += i;
		a %= n;
		if(a < 0) a += n;
		r.insert(a);
	}
	if(r.size() == n){
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}