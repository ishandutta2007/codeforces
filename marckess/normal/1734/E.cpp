#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

const int MX = 355;
int n, b[MX], a[MX][MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> b[i];
	
	forn (i, n)
	forn (j, n)
		a[i][j] = i * j % n;
	
	forn (i, n) {
		int off = MOD(b[i] - a[i][i], n);
		forn (j, n)
			cout << (a[i][j] + off) % n << " ";
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}