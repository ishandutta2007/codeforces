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

int x, y, n;
vi b;
vii a;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.emplace_back(x, i);
	}

	for (int i = 0; i < n; i++) {
		cin >> x;
		b.push_back(x);
	}

	cout << n / 2 + 1 << endl;

	sort (a.begin(), a.end(), greater<ii>());
	cout << a[0].se + 1 << " ";
	if ( n % 2 == 0 )
		cout << a[1].se + 1 << " ";

	for (int i = 2 - (n & 1); i < n; i += 2)
		if (b[a[i].se] > b[a[i+1].se])
			cout << a[i].se + 1 <<  " ";
		else
			cout << a[i+1].se + 1 << " ";

	cout << endl;

	return 0;
}