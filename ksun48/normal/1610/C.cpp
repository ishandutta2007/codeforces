#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	int s = 0;
	int e = n+1;
	while(s + 1 < e){
		int m = (s+e) / 2;
		int cur = 0;
		for(int i = 0; i < n; i++){
			if(cur <= b[i] && m - 1 - cur <= a[i]){
				cur++;
			}
		}
		if(cur >= m){
			s = m;
		} else {
			e = m;
		}
	}
	cout << s << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}