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

vi a(1e7 + 5), b(1e7 + 5);
int n, x, pad[200005], v[200005], acu = 0, suma = 0, sumb = 0;
bitset<200005> bs;

void obtPar(int u, int p) {
	if (v[u] == -1)
		return;

	if (p) {
		acu ^= v[u];
		a[v[u]]++;
		suma++;
	} else {
		b[v[u]]++;
		sumb++;
	}

	v[u] = -1;
	obtPar(pad[u], 1-p);
}

//Pierde al principio
ll res1() {
	ll res = 0;

	for (int i = 1; i <= 1e7; i++)
		if ((i ^ acu) <= 1e7)
			res += ll(a[i]) * ll(b[i^acu]);

	return res;
}

//Gana al principio
ll res2() {
	ll res = 0;

	res += ll(suma) * (suma - 1LL) / 2;
	res += ll(sumb) * (sumb - 1LL) / 2;

	for (int i = 1; i <= 1e7; i++)
		res += ll(a[i]) * ll(b[i]);

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i];

	bs.set();
	for (int i = 2; i <= n; i++) {
		cin >> pad[i];
		bs[pad[i]] = 0;
	}
	pad[1] = 1;

	for (int i = 1; i <= n; i++)
		if (bs[i])
			obtPar(i, 1);

	if (acu)
		cout << res1() << endl;
	else
		cout << res2() << endl;

	return 0;
}