#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> x(n);
	for(int i = 0; i < n; i++) cin >> x[i];
	const int B = 28;
	ll ans = 0;
	for(int r = 0; r < B; r++){
		vector<int> res;
		for(int a : x) res.push_back(a & ((2 << r) - 1));
		sort(res.begin(), res.end());
		auto count = [&](int val) -> ll {
			ll v = 0;
			int j = (int)res.size() - 1;
			for(int i = 0; i < j; i++){
				while(j > i && res[j] + res[i] >= val) j--;
				if(j > i){
					v += (j - i);
				}
			}
			return v;
		};
		ll q = count(4 << r) - count(3 << r) + count(2 << r) - count(1 << r);
		ans += ((q & 1) << r);
	}
	cout << ans << '\n';
}