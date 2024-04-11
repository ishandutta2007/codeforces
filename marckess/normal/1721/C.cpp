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
int n, a[MX], b[MX], mn[MX], mx[MX];

void main_() {
	cin >> n;
	forn (i, n) mx[i] = mn[i] = 0;
	forn (i, n) cin >> a[i];
	forn (i, n) cin >> b[i];
	
	int i = n - 1, last = i;
	while (i >= 0) {
		mn[i] = *lower_bound(b, b + n, a[i]) - a[i];
		mx[i] = b[last] - a[i];
		
		if (i && b[i - 1] < a[i])
			last = i - 1;
		
		i--;
	}
	
	forn (i, n) cout << mn[i] << " "; cout << endl;
	forn (i, n) cout << mx[i] << " "; cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}