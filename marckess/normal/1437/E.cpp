#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 500005;
int n, k, a[MX], res;
vi b;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	b = {0, n + 1};
	a[0] = -2e9, a[n + 1] = 2e9;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	forn (i, k) {
		int in;
		cin >> in;
		b.pb(in);
	}
	sort(all(b));
	for (int i = 1; i < b.size(); i++) {
		int l = b[i - 1], izq = a[l] - l;
		int r = b[i], der = a[r] - r;
		if (izq > der) {
			cout << -1 << endl;
			return 0;
		}
		vi lis;
		for (int k = l + 1; k < r; k++) {
			int x = a[k] - k;
			if (x < izq || der < x) continue;
			int j = upper_bound(all(lis), x) - lis.begin();
			if (j == lis.size()) lis.pb(x);
			else lis[j] = x;
		}
		res += r - l - 1 - (int)lis.size();
	}
	
	cout << res << endl;
	
	return 0;
}