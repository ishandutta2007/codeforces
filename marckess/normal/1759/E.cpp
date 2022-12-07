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
ll x;

void main_() {
	cin >> n >> x;
	forn (i, n)
		cin >> a[i];
	sort(a, a + n);
	
	int res = 0;
	vi v = {2, 2, 3};
	do {
		int i = 0, j = 0;
		ll act = x;
		while (i < n) {
			if (act > a[i]) {
				act += a[i] / 2;
				i++;
			} else if (j < 3) {
				act *= v[j];
				j++;
			} else {
				break;
			}
		}
		res = max(res, i);
	} while (next_permutation(all(v)));
	
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