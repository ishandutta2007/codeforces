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

const int MX = 200005, LG = 33;
int n;
ll a[MX], p[10][LG];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	forn (i, n)
		for (int j = LG - 1; j >= 0; j--)
			if (a[i] + p[a[i] % 10][j] <= 2e9)
				a[i] += p[a[i] % 10][j];
	
	forn (i, n - 1)
		if (a[i] != a[i + 1]) {
			cout << "No" << endl;
			return;
		}
	
	cout << "Yes" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	forn (i, 10)
		p[i][0] = i;
	
	forr (j, 1, LG - 1)
		forn (i, 10)
			p[i][j] = p[i][j - 1] + p[(i + p[i][j - 1]) % 10][j - 1];
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}