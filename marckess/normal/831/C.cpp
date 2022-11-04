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

int n, m;
const int off = 16e6;
ll a[2005], b[2005], acu, aux;
bitset<off*2+5> bs;
set<int> res;
bool f;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	acu = b[0];
	for (int i = 0; i < n; i++) {
		acu -= a[i];
		
		bs.reset();
		aux = acu;
		for (int j = 0; j < n; j++) {
			aux += a[j];
			bs[aux+off] = 1;
		}

		f = true;
		for (int j = 0; j < m; j++)
			f &= bs[b[j]+off];

		if (f)
			res.insert(acu);
	}

	cout << res.size() << endl;

	return 0;
}