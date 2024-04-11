#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	ll x, d;
	cin >> x >> d;
	//2^n - 1 non-empty subsequences
	std::vector<long long> ans;
	ll curr = 1;
	while(x > 0) {
		ll high = 0;
		while((((ll)1)<<(high+1))-1 <= x) ++high;
		x -= (((ll)1)<<high)-1;
		for (int i = 0; i < high; ++i) {
			ans.push_back(curr);
		}
		curr += d;
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}