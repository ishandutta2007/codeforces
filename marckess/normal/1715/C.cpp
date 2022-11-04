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

const int MX = 100005;
ll n, q, a[MX], tot;

void upd (int i, int k) {
	if (a[i] != a[i + 1])
		tot += k * (i + 1) * (n - i - 1);
}

void main_() {
	cin >> n >> q;
	forn (i, n)
		cin >> a[i];
	
	forn (i, n - 1)
		upd(i, 1);
	
	while (q--) {
		int i, x;
		cin >> i >> x;
		i--;
		
		if (i) upd(i - 1, -1);
		if (i + 1 < n) upd(i, -1);
		
		a[i] = x;
		
		if (i) upd(i - 1, 1);
		if (i + 1 < n) upd(i, 1);
		
		cout << tot + n * (n + 1) / 2 << endl;
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