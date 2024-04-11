#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 3005;
int n, ini[MX], fin[MX], ind = -1;
string a[MX], b[MX], s, t;

void no () {
	cout << "NO" << endl;
	exit(0);
}

vi kmp (string &s) {
	int i = 0, j = -1;
	vi b(s.size()+1, -1);
	
	while (i < s.size()) {
		while (j >= 0 && s[i] != s[j]) j = b[j];
		i++, j++;
		b[i] = j;
	}

	return b;
}

int find (string &p, vi &b, string &t) {
	int i = 0, j = 0;

	while (i < t.size()) {
		while (j >= 0 && t[i] != p[j]) j = b[j];
		i++, j++;
		if (j == p.size()) return i - j;
	}

	return -1;
}

bool esPos (int p[], int k) {
	if (0 > p[ind] + k || p[ind] + k >= a[ind].size()) return 0;

	int x = a[ind][p[ind] + k], y = b[ind][p[ind] + k];

	for (int i = 0; i < n; i++) {
		if (ini[i] == -1) continue;
		if (0 > p[i] + k || p[i] + k >= a[i].size()) return 0;
		if (a[i][p[i] + k] != x || b[i][p[i] + k] != y) return 0;
	}

	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(ini, -1, sizeof(ini));
	memset(fin, -1, sizeof(fin));

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	for (int i = 0; i < n; i++)
		if (a[i] != b[i]) {
			for (int j = 0; j < a[i].size(); j++) {
				if (a[i][j] == b[i][j]) continue;
				if (ini[i] == -1) ini[i] = j;
				fin[i] = j;
			}

			if (ind == -1) {
				ind = i;
				s = a[i].substr(ini[i], fin[i] - ini[i] + 1);
				t = b[i].substr(ini[i], fin[i] - ini[i] + 1);
			} else {
				if (a[i].substr(ini[i], fin[i] - ini[i] + 1) != s) no();
				if (a[i].substr(0, ini[i]) + t + a[i].substr(fin[i]+1) != b[i]) no();
			}
		}

	if (ind == -1) {
		cout << "YES" << endl << 'a' << endl << 'a' << endl;
		return 0;
	}

	string spre, ssuf, tpre, tsuf;

	while (esPos(ini, -1)) {
		for (int i = 0; i < n; i++)
			if (ini[i] != -1)
				ini[i]--;
		spre.pb(a[ind][ini[ind]]);
		tpre.pb(b[ind][ini[ind]]);
	}

	while (esPos(fin, 1)) {
		for (int i = 0; i < n; i++)
			if (fin[i] != -1)
				fin[i]++;
		ssuf.pb(a[ind][fin[ind]]);
		tsuf.pb(b[ind][fin[ind]]);
	}

	reverse(all(spre));
	reverse(all(tpre));

	s = spre + s + ssuf;
	t = tpre + t + tsuf;
	vi f = kmp(s);

	for (int i = 0; i < n; i++) {
		int k = find(s, f, a[i]);
		if (k != -1) a[i] = a[i].substr(0, k) + t + a[i].substr(k+t.size());
		if (a[i] != b[i]) no();
	}

	cout << "YES" << endl << s << endl << t << endl;

	return 0;
}