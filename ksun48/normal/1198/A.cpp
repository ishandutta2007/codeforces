#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, I;
	cin >> n >> I;
	I *= 8;
	ll f = I / n;
	f = min(f, 28ll);
	ll num_distinct = 1ll << f;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	vector<int> freq;
	int num = 0;
	for(int i = 0; i < n; i++){
		num += 1;
		if(i+1 == n || a[i] != a[i+1]){
			freq.push_back(num);
			num = 0;
		}
	}
	if((ll)freq.size() <= num_distinct){
		cout << 0 << '\n';
	} else {
		ll cur = 0;
		for(int i = 0; i < num_distinct; i++){
			cur += freq[i];
		}
		ll ans = cur;
		for(int i = 0; i + num_distinct < (int)freq.size(); i++){
			cur -= freq[i];
			cur += freq[i + num_distinct];
			ans = max(ans, cur);
		}

		cout << n - ans << '\n';
	}
}