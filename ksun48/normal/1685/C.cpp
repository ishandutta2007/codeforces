#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	n *= 2;
	vector<int> psum(n+1);
	for(int i = 0; i < n; i++){
		psum[i+1] = psum[i] + (s[i] == '(' ? 1 : -1);
	}
	assert(psum[n] == 0);
	int maxloc = 0;
	for(int i = 0; i <= n; i++) if(psum[i] >= psum[maxloc]) maxloc = i;
	int minloc = 0;
	for(int i = 0; i <= n; i++) if(psum[i] <= psum[minloc]) minloc = i;
	if(psum[minloc] >= 0){
		cout << 0 << '\n';
		return;
	}
	int first_neg = n;
	int last_neg = 0;
	for(int i = 0; i <= n; i++){
		if(psum[i] < 0){
			first_neg = min(first_neg, i);
			last_neg = max(last_neg, i);
		}
	}
	int pmloc = 0;
	int smloc = n;
	for(int i = 0; i < first_neg; i++){
		if(psum[i] >= psum[pmloc]) pmloc = i;
	}
	for(int i = n; i > last_neg; i--){
		if(psum[i] >= psum[smloc]) smloc = i;
	}
	int val = psum[pmloc] + psum[smloc] - psum[maxloc];
	if(val < 0){
		cout << 2 << '\n';
		cout << 1 << ' ' << maxloc << '\n';
		cout << (maxloc + 1) << ' ' << n << '\n';
	} else {
		cout << 1 << '\n';
		cout << (pmloc + 1) << ' ' << smloc << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}