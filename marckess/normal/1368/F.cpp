#include <bits/stdc++.h>
 
//#define endl '\n'
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

const int MX = 1005;
int n, a[MX];

int f (int k) {
	return n - (n + k - 1) / k - (k - 1);
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	int k = 1;

	for (int i = 1; i < n; i++)
		if (f(i) > f(k))
			k = i;

	int tot = 0;
	while (tot < f(k)) {
		vi v;

		for (int i = 0; i < n - 1 && v.size() < k; i++)
			if ((i + 1) % k && !a[i])
				v.pb(i);

		cout << v.size();
		for (int x : v) {
			cout << " " << x + 1;
			tot++;
			a[x] = 1;
		}
		cout << endl;

		int r;
		cin >> r;
		if (r == -1) exit(0);
		r--;

		for (int j = 0; j < v.size(); j++) {
			int i = (r + j) % n;
			tot -= a[i];
			a[i] = 0;
		}
	}

	cout << 0 << endl;

	return 0;
}