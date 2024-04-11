#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	int D;
	cin >> D;
	for(int& x : a) x -= D;
	int ans = 0;
	int ptake = 0;
	int64_t maxpsum = 0;
	int64_t rsum = 0;
	for(int x : a){
		if(ptake == 0){
			ans ++;
			ptake = 1;
			maxpsum = 0;
			rsum = x;
		} else {
			if(rsum + x < maxpsum){
				ptake = 0;
			} else {
				ans ++;
				ptake = 1;
				maxpsum = max(maxpsum, rsum);
				rsum += x;
			}
		}
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}