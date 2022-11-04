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
	int cn = 0;
	forn (i, n) {
		cin >> a[i];
		cn += a[i] < 0;
	}
	forn (i, n)
		if (i < cn)
			a[i] = -abs(a[i]);
		else
			a[i] = abs(a[i]);
	
	forn (i, n - 1)
		if (a[i] > a[i + 1]) {
			cout << "NO" << endl;
			return;
		}
	
	cout << "YES" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}