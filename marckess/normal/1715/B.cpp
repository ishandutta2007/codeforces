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
int n;
ll k, b, s, res[MX];

void main_() {
	cin >> n >> k >> b >> s;
	
	forn (i, n)
		res[i] = 0;
	
	ll mn = b * k;
	ll mx = b * k + n * (k - 1);
	
	if (mn <= s && s <= mx) {
		res[0] = b * k;
		s -= b * k;
		forn (i, n) {
			ll d = min(s, k - 1);
			s -= d;
			res[i] += d;
			cout << res[i] << " ";
		}
		cout << endl;
	} else {
		cout << -1 << endl;
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