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

typedef complex<ld> cld;

ld x, y, vx, vy, a, b, c, d;
cld v, res[10], o;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> x >> y >> vx >> vy >> a >> b >> c >> d;

	o = cld(x, y);
	v = cld(vx, vy);
	v /= abs(v);

	res[0] = (cld(x+b, y) - o) * v + o;
	res[1] = (cld(x, y+a/2) - o) * v + o;
	res[2] = (cld(x, y+c/2) - o) * v + o;
	res[3] = (cld(x-d, y+c/2) - o) * v + o;
	res[4] = (cld(x-d, y-c/2) - o) * v + o;
	res[5] = (cld(x, y-c/2) - o) * v + o;
	res[6] = (cld(x, y-a/2) - o) * v + o;

	cout << fixed << setprecision(15);
	for (int i = 0; i < 7; i++)
		cout << res[i].real() << " " << res[i].imag() << endl;

	return 0;
}