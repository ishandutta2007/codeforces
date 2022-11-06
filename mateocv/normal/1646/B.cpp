#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	for(int test_number = 0; test_number < t; test_number++){
		int n; cin >> n;
		vector <long long> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		vector <long long> prefix_sums = {0};
		for(int i = 0; i < n; i++){
			prefix_sums.push_back(prefix_sums.back() + a[i]);
		}
		vector <long long> suffix_sums = {0};
		for(int i = n - 1; i >= 0; i--){
			suffix_sums.push_back(suffix_sums.back() + a[i]);
		}
		bool answer = false;
		for(int k = 1; k <= n; k++){
			if(2 * k + 1 <= n){
				long long blue_sum = prefix_sums[k + 1];
				long long red_sum = suffix_sums[k];
				if(blue_sum < red_sum){
					answer = true;
				}
			}
		}
		if(answer) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}