#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, m;
int x[10], y;
bitset<10> ex;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> x[i];

	for (int i = 0; i < m; i++) {
		cin >> y;
		ex[y] = 1;
	}

	for (int i = 0; i < n; i++)
		if (ex[x[i]])
			cout << x[i] << " ";
	cout << endl;

	return 0;
}