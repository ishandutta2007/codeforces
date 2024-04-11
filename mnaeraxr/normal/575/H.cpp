#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 2000010;
const int64 mod = 1000000007;

int64 modexp(int64 v, int64 p){
	if (p == 0) return 1;
	int64 ans = modexp(v * v % mod, p / 2);
	if (p & 1) ans = ans * v % mod;
	return ans;
}

int64 f[maxn];
int64 inv[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	f[0] = 1;
	inv[0] = 1;
	for (int i = 1; i < 2 * n + 3; ++i){
		f[i] = f[i - 1] * i % mod;
		inv[i] = modexp(f[i], mod - 2);
	}


	int64 ans = f[2 * n + 2] * inv[n + 1] % mod * inv[n + 1] % mod - 1;
	if (ans == -1) ans = mod - 1;
	cout << ans << endl;

	return 0;
}