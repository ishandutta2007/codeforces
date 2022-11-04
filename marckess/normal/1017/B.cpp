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

const int MX = 100005;
ll n, x[2] = {0}, y[2] = {0};
string a, b;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		if (b[i] == '0') x[a[i]-'0']++;
		else y[a[i]-'0']++;
	}

	cout << x[0] * x[1] + x[0] * y[1] + x[1] * y[0] << endl;

	return 0;
}