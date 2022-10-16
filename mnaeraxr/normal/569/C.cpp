#include <bits/stdc++.h>

using namespace std;

const int maxn = 5000000;

bool primes[maxn];

void sieve(){
	for (int i = 2; i * i < maxn; ++i){
		if (primes[i]) continue;
		for (int j = i * i; j < maxn; j += i)
			primes[j] = true;
	}
}

int dig[13];

bool isPal(int v){
	int p = 0;
	while (v > 0){
		dig[p++] = v % 10;
		v /= 10;
	}
	for (int i = 0; i < p; ++i)
		if (dig[i] != dig[p - i - 1])
			return false;
	return true;
}

int main()
{
	int p, q;
	cin >> p >> q;

	sieve();

	int ans = 1;
	int pi = 0;
	int pal = 1;
	for (int i = 2; i < maxn; ++i){
		if (isPal(i)) ++pal;
		if (!primes[i]) ++pi;
		if (1LL * q * pi <= 1LL * p * pal)
			ans = i;
	}
	cout << ans << endl;
}