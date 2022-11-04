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

const int MX = 1000005;
int n, a;
vi pos[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		pos[a].push_back(i);
	}

	int mx = 0, a = 0, b = 1e9;
	for (int i = 1; i < MX-1; i++)
		mx = max(mx, int(pos[i].size()));

	for (int i = 1; i < MX-1; i++)
		if (pos[i].size() == mx)
			if (pos[i].back() - pos[i].front() < b - a) {
				a = pos[i].front();
				b = pos[i].back();
			}

	cout << a << " " << b << endl;

	return 0;
}