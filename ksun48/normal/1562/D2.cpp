#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, q;
	cin >> n >> q;
	string _s;
	cin >> _s;
	vector<int> which(n);
	for(int i = 0; i < n; i++){
		which[i] = (_s[i] == '-') != (i & 1);
	}
	vector<int> psum(n+1, 0);
	for(int i = 0; i < n; i++){
		psum[i+1] = psum[i] + (which[i] ? -1 : 1);
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		l--; r--;
		if(psum[r+1] == psum[l]){
			cout << 0 << '\n';
			cout << '\n';
		} else {
			if((r+1-l) & 1){
				cout << 1 << '\n';
			} else {
				cout << 2 << '\n';
				cout << (r+1) << ' ';
				r--;
			}
			int d = min(psum[l], psum[r+1]) + abs(psum[l] - psum[r+1]) / 2;
			// d -> d+1
			int s = l;
			int e = r+1;
			while(s + 1 < e){
				int m = (s + e) / 2;
				if((psum[m] <= d) == (psum[s] <= d)){
					s = m;
				} else {
					e = m;
				}
			}
			cout << (s+1);
			cout << '\n';
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}