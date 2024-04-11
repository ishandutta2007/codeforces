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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int c, n, a[MX], cn[MX], to[MX];
vi st;

bool esPos (int nw) {
	int acu = 0, j = st.size();

	while (acu < c) {
		j = min(j, to[acu]);

		if (nw && (j == -1 || st[j] <= nw) && acu + nw <= c) {
			int k = min(cn[nw], (c - acu) / nw);
			acu += nw * k;
			if (j != -1 && st[j] == nw) j--;
			nw = 0;
		} else if (j != -1) {
			int k = min(cn[st[j]], (c - acu) / st[j]);
			acu += st[j] * k;
			j--;
		} else return 0;
	}

	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> c >> n;
	
	forn (i, n) {
		cin >> a[i];
		cn[a[i]]++;
		st.pb(a[i]);
	}

	sort(all(st));
	st.erase(unique(all(st)), st.end());

	for (int i = 0; i < c; i++) {
		int j = upper_bound(all(st), c - i) - st.begin();
		to[i] = j - 1;
	}

	if (!esPos(0)) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 1; i < c; i++) {
		cn[i]++;

		if (!esPos(i)) {
			cout << i << endl;
			return 0;
		}

		cn[i]--;
	}

	cout << "Greed is good" << endl;
	
	return 0;
}