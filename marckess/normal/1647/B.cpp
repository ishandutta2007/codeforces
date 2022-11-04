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

const int MX = 105;
int n, m;
string s[MX];

void main_() {
	cin >> n >> m;
	forn (i, n)
		cin >> s[i];
	
	forn (i, n - 1)
	forn (j, m - 1) {
		int a = s[i][j] == '1';
		int b = s[i][j + 1] == '1';
		int c = s[i + 1][j] == '1';
		int d = s[i + 1][j + 1] == '1';
		
		if (a + b + c + d == 3) {
			cout << "NO" << endl;
			return;
		}
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