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

const int MX = 1000005;
int n, m, hp[MX], aux[MX], s, res;
vi a;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> hp[i];
		aux[i] = hp[i];
		s += hp[i];
	}

	res = (s + n - 1) / n;

	for (int i = 0, j = 0; i < res; i++) {
		int act = 0;
		
		while (act < n && j < m) {
			int d = min(aux[j], n - act);
			
			aux[j] -= d;
			if (!aux[j]) j++;
			
			act += d;
			if (j < m)
				a.pb(act);
		}
	}

	a.pb(n);
	sort(all(a));
	a.erase(unique(all(a)), a.end());

	for (int i = (int)a.size() - 1; i; i--)
		a[i] -= a[i-1];

	while (a.size() < m) a.pb(0);

	cout << res << endl;
	for (int i = 0; i < m; i++)
		cout << a[i] << " ";
	cout << endl;

	for (int i = 0, j = 0; i < res; i++) {
		for (int k = 0; k < m; k++) {
			cout << j + 1 << " ";
			hp[j] -= a[k];
			if (j < m - 1 && !hp[j]) j++;
		}
		cout << endl;
	}

	return 0;
}