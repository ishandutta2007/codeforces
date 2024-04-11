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

const int MX = 200005;
int n, s, a, f;
ll res = 0;
vi x, y;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a < s) x.pb(s-a);
		if (a > s) y.pb(a-s);
	}

	sort(ALL(x)), sort(ALL(y));

	if (x.size() > n / 2)
		for (int i = 0; i < x.size() - n / 2; i++)
			res += x[i];

	if (y.size() > n / 2)
		for (int i = 0; i < y.size() - n / 2; i++)
			res += y[i];

	cout << res << endl;

	return 0;
}