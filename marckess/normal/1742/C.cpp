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

char a[11][11];

void main_() {
	forn (i, 8)
	forn (j, 8)
		cin >> a[i][j];
	
	forn (i, 8) {
		int cn = 0;
		forn (j, 8)
			cn += a[i][j] == 'R';
		if (cn == 8) {
			cout << "R" << endl;
			return;
		}
	}
	
	forn (j, 8) {
		int cn = 0;
		forn (i, 8)
			cn += a[i][j] == 'B';
		if (cn == 8) {
			cout << "B" << endl;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}