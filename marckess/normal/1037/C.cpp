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
typedef vector<ii> vii;

int n, res = 0;
string a, b;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++)
		res += a[i] != b[i];

	for (int i = 0; i < n-1; i++)
		if (a[i] != a[i+1] && a[i] != b[i] && a[i+1] != b[i+1]) {
			res--;
			i++;
		}

	cout << res << endl;

	return 0;
}