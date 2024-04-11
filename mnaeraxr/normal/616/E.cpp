#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;
const int64 mod = 1000000007;

int64 comb(int64 tot){
	if (tot & 1)
		return (tot - 1) / 2 % mod * (tot % mod) % mod;
	else
		return tot / 2 % mod * ((tot - 1)  % mod) % mod;
}

int64 calc(int64 start, int64 step, int64 tot){
	return (start % mod * (tot % mod) % mod + (step % mod) * comb(tot) % mod ) % mod;
}

int64 find(int64 n, int64 start){
	int64 lo = 0, hi = start;
	int64 step = n / start;

	while (lo + 1 < hi){
		int64 mid = (lo + hi) / 2;
		if (n / mid == step) hi = mid;
		else lo = mid;
	}

	return start - lo;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 n, m;
	cin >> n >> m;

	int64 ans = 0;

	if (m > n){
		ans = n % mod * ((m - n) % mod) % mod;
		m = n;
	}

	while (m){
		int64 tot = find(n, m);
		ans = (ans + calc(n % m, n / m, tot)) % mod;
		m = m - tot;
	}

	cout << ans << endl;

	return 0;
}