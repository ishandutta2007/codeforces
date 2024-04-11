#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, z, x[MX], res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> z;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	sort(x, x+n);

	int i = 0, j = n / 2;
	while (i < n / 2) {
		while (j < n && x[j] - x[i] < z) j++;
		if (j < n) res++, j++;
		i++;
	}

	cout << res << endl;

	return 0;
}