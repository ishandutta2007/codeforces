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

const int MX = 1e7;
int n;
bitset<MX+2> bs;
vector<ll> pr;

void criba () {
	bs.set();
	bs[0] = bs[1] = 0;

	for (ll i = 2; i <= MX; i++)
		if (bs[i]) {
			pr.push_back(i);
			for (ll j = i*i; j <= MX; j += i)
				bs[j] = 0;
		}
}

bool esPrimo (ll n) {
	if (n <= MX)
		return bs[n];

	for (int i = 0; pr[i] * pr[i] <= n; i++)
		if (n % pr[i] == 0)
			return false;

	return true;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	criba();

	cin >> n;

	if (esPrimo(n))
		cout << 1 << endl;
	else if (n % 2 == 0)
		cout << 2 << endl;
	else if (esPrimo(n - 2))
		cout << 2 << endl;
	else
		cout << 3 << endl;

	return 0;
}