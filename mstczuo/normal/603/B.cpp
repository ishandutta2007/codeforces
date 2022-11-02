# include <iostream>

using namespace std;

typedef long long ll;

const int Mod = 1000000007;
const int maxn = 1000000+10;

bool v[maxn];
int main() {
	int p, k, cnt = 0, ans = 1;
	cin >> p >> k;
	if(k == 0) {
		for(int j = 1; j < p; ++j)
			ans = (ll)ans * p % Mod;
	} else if(k == 1) {
		for(int j = 0; j < p; ++j)
			ans = (ll)ans * p % Mod;
	} else {
		for(int i = 1; i < p; ++i) if(!v[i]) {
			v[i] = true;
			for(int j = (ll)i * k % p; j != i; j = (ll)j * k % p)
				v[j] = true;
			cnt += 1;
			ans = (ll) ans * p % Mod;
		}
	}
	cout << ans << endl;
}