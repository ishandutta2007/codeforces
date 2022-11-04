#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005;
int n;
ll a[MX], b[MX], h, res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
		
	cin >> n >> h;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	int i = 0, j = 0;
	ll acu = h;

	while (i < n) {
		while (j + 1 < n)
			if (a[j+1] - b[j] < acu) {
				acu -= a[j+1] - b[j];
				j++;
			} else {
				break;
			}

		res = max(res, b[j] - a[i] + acu);

		if (i == j) {
			i++, j++;
			acu = h;
		} else {
			acu += a[i+1] - b[i];
			i++;
		}
	}

	cout << res << endl;

	return 0;
}