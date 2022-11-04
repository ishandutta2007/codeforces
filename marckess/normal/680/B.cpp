#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, a, t[105], res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> a;
	for (int i = 0; i < n; i++)
		cin >> t[i];

	int i = a-1, j = i;

	while (i >= 0 || j < n) {
		if (i >= 0 && j < n) {
			if (t[i] && t[j])
				res += 1 + (i != j);
		} else if (i >= 0)
			res += t[i];
		else
			res += t[j];
		i--;
		j++;
	}

	cout << res << endl;

	return 0;
}