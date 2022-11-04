#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int d, h, v, e;
	ld r, pi = acos(ld(-1.0));

	cin >> d >> h >> v >> e;

	r = v / (pi * (d * d / 4.0));

	if (e - r > -1e-9)
		cout << "NO" << endl;
	else
		cout << fixed << setprecision(5)
			 << "YES" << endl << h / (r - e)<< endl;

	return 0;
}