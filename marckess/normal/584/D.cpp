#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

const int M = 1e5+2;
bitset<M> bs;
vi pr;

void criba() {
	bs.set();
	bs[0] = bs[1] = 0;

	for (ll i = 2; i < M; i++) {
		if (bs[i]) {
			pr.push_back(i);
			for (ll j = i*i; j < M; j+=i)
				bs[j] = 0;
		}
	}
}

bool esPrimo (int n) {
	for (int i = 0; pr[i] * pr[i] <= n; i++)
		if (n % pr[i] == 0)
			return false;
	return true;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	criba();
	int n;
	cin >> n;

	if (esPrimo(n))
		cout << 1 << endl << n << endl;
	else if (n % 2 == 0) {
		for (int i = 0; i < pr.size(); i++) {
			if (esPrimo(n-pr[i])) {
				cout << 2 << endl << pr[i] << " " << n - pr[i] << endl;
				break;
			}
		}
	} else {
		n -= 3;
		for (int i = 0; i < pr.size(); i++) {
			if (esPrimo(n-pr[i])) {
				cout << 3 << endl << 3 << " " << pr[i] << " " << n - pr[i] << endl;
				break;
			}
		}
	}

	return 0;
}