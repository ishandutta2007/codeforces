#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int tri[3], x, res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> x >> tri[0];

	tri[1] = tri[2] = tri[0];

	while (tri[0] < x || tri[1] < x || tri[2] < x) {
		sort(tri, tri+3);
		tri[0] = min(x, tri[1] + tri[2] - 1);
		res++;
	}

	cout << res << endl;

	return 0;
}