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
int n, k, res[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	if (n == k) {
		cout << -1 << endl;
		return 0;
	}

	while (k--) {
		res[n-1] = n;
		n--;
	}

	for (int i = 0; i < n; i++)
		res[i] = (i+1)%n+1;

	int i = 0;
	while (res[i]) cout << res[i++] << " ";
	cout << endl;

	return 0;
}