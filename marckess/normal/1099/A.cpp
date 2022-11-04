#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int w, h;
int u1, d1;
int u2, d2;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> w >> h;
	cin >> u1 >> d1;
	cin >> u2 >> d2;

	while (h > 0) {
		w += h;
		if (h == d1) w = max(0, w - u1);
		if (h == d2) w = max(0, w - u2);
		h--;
	}

	cout << w << endl;

	return 0;
}