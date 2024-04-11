#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 10;
const int maxd = 100000;

int pos[ maxn ];

int total;
int value[ maxd ];
int freq[ maxd ];
int dp[ maxd ];
int from[ maxd ];
set<int> who[ maxd ];

int modpow(int a, int b, int m){
	int c = 1;

	while (b){
		if (b & 1)
			c = 1LL * c * a % m;
		a = 1LL * a * a % m;
		b >>= 1;
	}
	return c;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int total = 0;
	for (int i = 1; i <= m; ++i){
		if (m % i == 0){
			pos[ i ] = total;
			value[ total++ ] = i;
		}
	}

	int phi = m, lm = m;
	for (int i = 2; i * i <= lm; ++i){
		if (lm % i == 0){
			phi = phi / i * (i - 1);
			while (lm % i == 0)
				lm /= i;
		}
	}
	if (lm > 1) phi = phi / lm * (lm - 1);

	for (int i = 1; i <= m; ++i){
		int g = __gcd(i, m);
		int p = pos[ g ];

		who[ p ].insert( i );
		freq[ p ]++;
	}

	for (int i = 0; i < n; ++i){
		int v; cin >> v;
		if (v == 0) v = m;

		int g = __gcd(v, m);
		int p = pos[ g ];

		who[ p ].erase( v );
		freq[ p ]--;
	}

	for (int i = 0; i < total; ++i){
		dp[i] = freq[i];
		from[i] = -1;

		for (int j = 0; j < i; ++j)
			if (value[i] % value[j] == 0){
				int nValue = freq[i] + dp[j];
				if (nValue > dp[i]){
					dp[i] = nValue;
					from[i] = j;
				}
			}
	}

	vector<int> lst;

	int pos = total - 1;

	while (pos != -1){
		for (auto v : who[pos])
			lst.push_back(v);
		pos = from[pos];
	}

	reverse(lst.begin(), lst.end());

	if (lst.back() == m)
		lst.back() = 0;

	int x = 1;

	cout << dp[total - 1] << endl;

	for (auto z : lst){

		int a = __gcd(x, m);
		int xp = x / a;

		int b = __gcd(z, m);
		int zp = z / b;

//		assert(b % a == 0);

		int y = 1LL * (b / a) * zp % m * modpow(xp, phi - 1, m) % m;

		cout << y << " ";
//		cout << z << " ";
//		assert( x * y % m == z );
		x = z;
	}

	cout << endl;

	return 0;
}