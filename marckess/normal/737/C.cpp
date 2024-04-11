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

const int MX = 200005;
int n, s, a[MX], lvl[MX], k, res = 0, ml = 0, c = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		lvl[a[i]]++;
	}

	if (a[s]) {
		lvl[a[s]]--;
		lvl[0]++;
		res++;
	}

	k = lvl[0] - 1;
	res += k;
	lvl[0] = 1;

	for (int i = 1; i < n; i++) {
		if (!lvl[i]) {
			if (k) {
				lvl[i]++;
				k--;
			}
		}
		if (lvl[i]) ml = i;
	}

	for (int i = 0; i < ml; i++)
		if (!lvl[i]) c++;

	int i = 0, j = ml;
	while (c > 0) {
		while (lvl[i]) i++;
		lvl[i]++;
		c--;
		lvl[j]--;
		res++;
		if (!lvl[j]) {
			j--;
			while (!lvl[j]) {
				j--;
				c--;
			}
		}
	}

	cout << res << endl;

	return 0;
}