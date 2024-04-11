#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 30000000;
const int maxp = 20;

int sieve[maxn];

void buildSieve(int n){
	sieve[1] = 1;
	for (int64 i = 2; i * i < n; ++i){
		if (!sieve[i]){
			sieve[i] = i;
			for (int64 j = i * i; j < n; j += i)
				if (!sieve[j]) sieve[j] = i;
		}
	}
	for (int64 i = 2; i < n; ++i)
		if (!sieve[i]) sieve[i] = i;
}

bool isPrime(int n){
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) return false;
	return true;
}

vector<int> primes(int n){
	vector<int> ans;
	for (int i = 2; (int)ans.size() < n; ++i)
		if (isPrime(i)) ans.push_back(i);
	return ans;
}

int brute(int n, int p, vector<int> &plist){
	int idx = 0;
	while (plist[idx] < p) ++idx;

	int ans = 0;
	n /= p;

	for (int i = 1; i < (1 << idx); ++i){
		int cur = 1;
		bool ok = true;
		for (int j = 0; j < idx && ok; ++j){
			if (i >> j & 1){
				if (cur > n / plist[j])
					ok = false;
				else
					cur *= plist[j];
			}
		}
		if (!ok) continue;
		if (__builtin_popcount(i) & 1) ans += n / cur;
		else ans -= n / cur;
	}
	return n - ans;
}

int smart(int n, int p){
	int ans = 0;
	n /= p;
	for (int i = 1; i <= n ; ++i)
		if (sieve[i] == 1 || sieve[i] >= p)
			++ans;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	auto p = primes(20);
//	for (auto v : p) cout << v << endl;

	int a, b, k;
	cin >> a >> b >> k;

	if (!isPrime(k)){
		cout << 0 << endl;
		exit(0);
	}

	if (k <= p.back()){
		cout << brute(b, k, p) - brute(a - 1, k, p) << endl;
	}
	else{
		buildSieve(b / k + 1);
		cout << smart(b, k) - smart(a - 1, k) << endl;
	}

	return 0;
}