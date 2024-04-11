#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	vector<int> freq(n+1, 0);
	for(int x : a) freq[x]++;
	int cf = 0;
	int j = 0;
	int best = n+2;
	pair<int,int> best_pair = {-1, -1};
	for(int i = 0; i <= n; i++){
		while(j <= n && cf - (n - cf) < k){
			cf += freq[j];
			j++;
		}
		if(cf - (n - cf) >= k){
			if(j-i < best){
				best = j-i;
				best_pair = {i, j};
			}
		}
		if(i < n) cf -= freq[i];
	}
	assert(best < n+2);
	auto [x, y] = best_pair;
	cout << x << ' ' << (y-1) << '\n';
	vector<int> pmaxes;
	int pmax = -1;
	int cval = 0;
	for(int i = 0; i <= n; i++){
		if(cval > pmax){
			pmax = cval;
			pmaxes.push_back(i);
		}
		if(i < n && a[i] >= x && a[i] < y){
			cval++;
		} else {
			cval--;
		}
	}
	pmaxes.resize(k);
	pmaxes.push_back(n);
	for(int i = 0; i < k; i++){
		cout << (pmaxes[i] + 1) << ' ' << (pmaxes[i+1]) << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}