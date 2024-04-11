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

string s;
int cn[256], ini, fin;
char d, res[2][13];

void ans () {
	forn (i, 2) {
		forn (j, 13) {
			if (!res[i][j]) res[i][j] = '*';
			cout << res[i][j];
		}
		cout << endl;
	}

	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;

	forn (i, 26) if (s[i] == s[i + 1]) {
		cout << "Impossible" << endl;
		return 0;
	}

	forn (i, 27) {
		if (cn[s[i]]) d = s[i];
		cn[s[i]]++;
	}

	ini = fin = -1;
	forn (i, 27) if (s[i] == d) {
		if (ini != -1) fin = i;
		else ini = i;
	}

	if (ini > 26 - fin) {
		swap(ini, fin);
		ini = 26 - ini;
		fin = 26 - fin;
		reverse(all(s));
	}

	int i = 0, j = 12 - (fin - ini - 1) / 2, k = ini;

	res[i][j] = d;
	j++;
	k++;

	if (j == 13) {
		j = 12;
		i = 1;
	}

	while (k < fin) {
		res[i][j] = s[k];

		if (i) j--;
		else {
			j++;
			if (j == 13) {
				j = 12;
				i = 1;
			}
		}

		k++;
	}

	k++;

	while (k < 27) {
		res[i][j] = s[k];

		if (i) {
			j--;
			if (j < 0) {
				j = 0;
				i = 0;
			}
		} else j++;

		k++;
	}

	k = 0;

	while (k < ini) {
		res[i][j] = s[k];
		j++;
		k++;
	}

	ans();
	
	return 0;
}