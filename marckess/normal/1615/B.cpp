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
int cn[20][MX];

void main_() {
	int l, r;
	cin >> l >> r;
	
	int res = 0;
	forn (j, 20)
		res = max(res, cn[j][r] - cn[j][l - 1]);
	
	cout << r - l + 1 - res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	forn (j, 20)
		for (int i = 1; i < MX; i++)
			cn[j][i] = cn[j][i - 1] + bool(i & (1 << j));
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}