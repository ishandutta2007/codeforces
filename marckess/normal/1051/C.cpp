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
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 105;
int n, a[MX], acu[MX], rep = -1;
vi un;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		acu[a[i]]++;
	}

	for (int i = 0; i < n; i++)
		if (acu[a[i]] == 1)
			un.pb(i);
		else if (acu[a[i]] > 2)
			rep = i;

	string res(n, 'A');

	if (un.size() % 2 && rep == -1) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

	int f = 0;
	for (int x : un) {
		res[x] = 'A'+f;
		f = 1 - f;
	}

	if (f)
		res[rep] = 'B';

	cout << res << endl;

	return 0;
}