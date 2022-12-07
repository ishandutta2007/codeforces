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

const int MX = 300005;
ll n;

void main_() {
	cin >> n;
	
	if (n % 2 == 0) {
		forr (i, 1, n / 2)
			cout << n + i << " " << n - i << " ";
		cout << endl;
	} else {
		vi res(n);
		forn (i, n) {
			res[i] = 2 * i + 1;
		}
		
		ll x = n * n;
		ll y = 4 * (n - 1) * (n - 1);
		
		ll dif = (y - x) / n;
		forn (i, n) {
			res[i] += dif;
			y -= res[i];
		}
		
		for (int i = n - 2; i > 0; i--) {
			ll d = res[i + 1] - res[i] - 1;
			d = min(d, y);
			res[i] += d;
			y -= d;
		}
		
		forn (i, n)
			cout << res[i] << " ";
		cout << endl;
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