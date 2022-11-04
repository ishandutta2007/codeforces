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

const int MX = 262144 + 5;
int n, p[MX], cn;

vi go (int i, int j) {
	if (i == j) return {p[i]};
	
	int m = (i + j) / 2;
	vi a = go(i, m);
	vi b = go(m + 1, j);
	
	if (a[0] > b[0]) {
		cn++;
		swap(a, b);
	}
	
	for (int x : b)
		a.pb(x);
	
	return a;
}

void main_() {
	cin >> n;
	forr (i, 1, n)
		cin >> p[i];
	
	cn = 0;
	vi r = go(1, n);
	
	if (is_sorted(all(r))) cout << cn << endl;
	else cout << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}