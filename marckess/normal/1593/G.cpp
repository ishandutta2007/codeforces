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

const int MX = 1000005;
int n, q, cn[2][MX];
string s;

void main_() {
	cin >> s;
	
	for (int i = 1; i <= s.size(); i++) {
		forn (x, 2) cn[x][i] = cn[x][i - 1];
		cn[i % 2][i] += s[i - 1] == '[' || s[i - 1] == ']';
	}
	
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		
		cout << abs(
			(cn[0][r] - cn[0][l - 1]) -
			(cn[1][r] - cn[1][l - 1])
		) << endl;
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