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

const int MX = (1 << 17) + 5;
int a[MX], l, r;

int findmx (int x) {
	int i = 0, j = r - l, res = 0;
	
	for (int k = 16; k >= 0; k--) {
		int m = lower_bound(a + i, a + j + 1, res + (1 << k)) - a;
		
		if (x & (1 << k)) {
			if (i < m) {
				j = m - 1;
			} else {
				res += 1 << k;
			}
		} else {
			if (m <= j) {
				i = m;
				res += 1 << k;
			}
		}
	}
	
	return res ^ x;
}

void main_() {
	cin >> l >> r;
	
	forn (i, r - l + 1)
		cin >> a[i];
	sort(a, a + (r - l + 1));
	
	forn (i, r - l + 1)
		if (findmx(a[i]) == r) {
			cout << a[i] << endl;
			return;
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