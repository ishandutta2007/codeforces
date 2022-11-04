#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 500005;
int n, a[MX], res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	a[0] = a[1];
	a[n+1] = a[n];
	n++;

	int i = 0, j = 1;

	while (j <= n) {
		if (a[j] == a[j-1]) {

			if (j - i > 2) {
				res = max(res, (j-i+1)/2-1);

				if (a[i] == a[j-1])
					fill(a+i, a+j, a[i]);
				else {
					fill(a+i, a+(i+j)/2, a[i]);
					fill(a+(i+j)/2, a+j, 1-a[i]);
				}
			}

			i = j;
		}
		j++;
	}

	cout << res << endl;
	for (int i = 1; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}