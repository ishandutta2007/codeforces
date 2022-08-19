#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> same(n-1);
	for(int i = 0; i < n-1; i++){
		same[i] = s[i] == s[i+1];
	}
	vector<int> psum(n, 0);
	vector<int> pdsum(n, 0);
	vector<vector<int> > cnt(2, vector<int>(n));
	for(int i = 0; i < n-1; i++){
		psum[i+1] = psum[i] + same[i];
		pdsum[i+1] = pdsum[i] ^ (1 - same[i]);
		cnt[0][i+1] = cnt[0][i];
		cnt[1][i+1] = cnt[1][i];
		cnt[pdsum[i+1]][i+1] += same[i];
	}
	for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		l--; r--;
		// l -> r-1
		int a = cnt[0][r] - cnt[0][l];
		int b = cnt[1][r] - cnt[1][l];
		int ans = max(a, b) + 1;
		cout << ans << '\n';
	}
}