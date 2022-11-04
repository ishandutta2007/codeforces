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

const int MX = 100005;
int n, a[MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	int res = max(0, n - 2);
	forn (i, n)
		for (int j = i + 1; j < n; j++) {
			int d = a[j] - a[i];
			int k = j - i;
			int g = abs(__gcd(d, k));
			
			d /= g;
			k /= g;
			
			int p = 0;
			for (int x = i, y = a[i]; x < n; x += k, y += d)
				p += a[x] == y;
			
			res = min(res, n - p);
		}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}