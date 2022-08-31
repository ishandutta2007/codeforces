#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	int cgcd = 0;
	vector<int> used(n, 0);
	for(int j = 0; j < n; j++){
		int bidx = -1;
		int best = 0;
		for(int i = 0; i < n; i++){
			if(used[i]) continue;
			int g = __gcd(a[i], cgcd);
			if(g >= best){
				best = g;
				bidx = i;
			}
		}
		used[bidx] = 1;
		cout << a[bidx] << ' ';
		cgcd = best;
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}