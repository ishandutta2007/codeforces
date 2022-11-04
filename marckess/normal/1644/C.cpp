// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5005;
int n, x, a[MX];
ll res[MX];

void main_() {
	cin >> n >> x;
	forn (i, n)
		cin >> a[i];
	
	fill(res, res + MX, -2e9);
	
	forn (i, n) {
		ll s = 0;
		forr (j, i, n - 1) {
			s += a[j];
			res[j - i + 1] = max(res[j - i + 1], s);
		}
	}
	
	for (int i = n - 1; i >= 0; i--)
		res[i] = max(res[i], res[i + 1]);
	
	forn (i, n + 1) {
		res[i] += i * x;
		if (i)
			res[i] = max(res[i], res[i - 1]);
		cout << max(0ll, res[i]) << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}