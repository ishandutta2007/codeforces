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

const int MX = 200005;
int n, a[MX];

void main_() {
	cin >> n;
	ll x = 0, y = 0, tot = 0, res = 0;
	forr (i, 1, n) {
		cin >> a[i];
		if (a[i] == 0) {
			y++;
			tot += x;
		} else {
			x++;
		}
	}
	x = 0;
	res = tot;
	forr (i, 1, n) {
		if (a[i] == 0) {
			y--;
			res = max(res, tot - x + y);
		} else {
			res = max(res, tot - y + x);
			x++;
		}
	}
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