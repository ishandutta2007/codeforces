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

ll a, b, acu = 1;
bool res = true;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> a >> b;
	while ( res ? a >= acu : b >= acu ) {
		if (res)
			a -= acu;
		else
			b -= acu;

		acu++;
		res ^= 1;
	}

	if (res)
		cout << "Vladik" << endl;
	else
		cout << "Valera" << endl;

	return 0;
}