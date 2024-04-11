#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1000001;
const int64 mod = 1000000007;

int prime[maxn];
int64 tab[maxn][21];

void sieve(){
	for (int i = 2; i * i < maxn; ++i){
		if (prime[i]) continue;

		for (int j = i * i; j < maxn; j += i)
			prime[j] = i;
	}

	for (int i = 0; i < maxn; ++i)
		if (prime[i] == 0) prime[i] = i;
}

int main(){

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	sieve();

	for (int i = 0; i <= 20; ++i)
		tab[0][i] = 2;

	tab[0][0] = 1;

	for (int i = 1; i < maxn; ++i){
		tab[i][0] = 1;
		for (int j = 1; j <= 20; ++j)
			tab[i][j] = (tab[i][j - 1] + tab[i - 1][j]) % mod;
	}

	int q; 
	scanf("%d", &q);

	while (q--){
		int a, b;
		scanf("%d%d", &a, &b);

		int64 answer = 1;

		while (b > 1){
			int p = prime[b];
			int cnt = 0;
			
			while (b % p == 0){
				cnt++;
				b /= p;
			}

			answer = answer * tab[a][cnt] % mod;
		}

		printf("%d\n", (int)answer);
	}

	return 0;
}