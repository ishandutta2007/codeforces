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

const int MX = 200005;
int n, a[MX], ex[MX];

void main_() {
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		ex[i] = 0;
	}
	
	for (int i = 1; i + 1 < n; i++)
		ex[i] = a[i] > a[i - 1] && a[i] > a[i + 1];
	
	int res = 0;
	for (int i = 1; i + 1 < n; i++)
		if (ex[i - 1] && ex[i + 1]) {
			ex[i - 1] = ex[i + 1] = 0;
			a[i] = max(a[i - 1], a[i + 1]);
			res++;
		}
	
	forn (i, n)
		if (ex[i]) {
			ex[i] = 0;
			a[i] = max(a[i - 1], a[i + 1]);
			res++;
		}
	
	cout << res << endl;
	forn (i, n)
		cout << a[i] << " ";
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