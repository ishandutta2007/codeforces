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

const int MX = 1005;
int n, mx[MX];

void main_() {
	cin >> n;
	fill(mx, mx + MX, -1e9);
	
	forn (i, n) {
		int a;
		cin >> a;
		mx[a] = i + 1;
	}
	
	int res = -1;
	forr (i, 1, MX - 1)
	forr (j, 1, MX - 1)
		if (__gcd(i, j) == 1)
			res = max(res, mx[i] + mx[j]);
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