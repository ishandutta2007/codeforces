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

int count (int x) {
	int res = 0;
	while (x % 2 == 0) {
		x /= 2;
		res++;
	}
	return res;
}

void main_() {
	cin >> n;
	
	int x = 0;
	vi b;
	
	forr (i, 1, n) {
		cin >> a[i];
		x += count(a[i]);
		b.pb(count(i));
	}
	
	sort(all(b), greater<int>());
	
	int res = 0;
	forn (i, n)
		if (x < n)
			res++,
			x += b[i];
	
	if (x >= n)
		cout << res << endl;
	else
		cout << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}