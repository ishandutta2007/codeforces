#include <bits/extc++.h>
using namespace std;

using ll = long long;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { // To use most bits rather than just the lowest ones:
	const uint64_t C = ll(4e18 * acos(0)) | 71; // large odd number
	ll operator()(ll x) const { return __builtin_bswap64((x^RANDOM)*C); }
};
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	const int B = 30;

	vector<ll> c01(B, 0), c10(B, 0);
	for(int j = 0; j < B; j++){
		__gnu_pbds::gp_hash_table<ll, int, chash> freqs({},{},{},{}, {1 << 16});
		for(int& x : a){
			freqs[x]++;
			int v = freqs[x ^ 1];
			if(x & 1){
				c01[j] += v;
			} else {
				c10[j] += v;
			}
			x /= 2;
		}
	}
	ll ans = 0;
	int best = 0;
	for(int i = 0; i < B; i++){
		if(c10[i] <= c01[i]){
			ans += c10[i];
		} else {
			ans += c01[i];
			best ^= (1 << i);
		}
	}
	cout << ans << ' ' << best << '\n';
}