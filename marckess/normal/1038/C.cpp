#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;
int n;
vi a, b;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	a.resize(n), b.resize(n);

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	sort(ALL(a), greater<int>());
	sort(ALL(b), greater<int>());

	int i = 0, j = 0;
	ll sum = 0;

	while (i < n || j < n) {
		if (j == n) sum += a[i++];
		else if (i == n) j++;
		else if (a[i] > b[j]) sum += a[i++];
		else j++;

		swap(i, j);
		swap(a, b);
		sum *= -1;
	}

	cout << sum << endl;

	return 0;
}