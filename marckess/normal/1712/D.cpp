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
int n, k, p[MX], a[MX];

int f (int m) {
	int res = 0;
	forn (i, n) {
		a[i] = p[i];
		
		if (2 * a[i] < m) {
			a[i] = (m + 1) / 2;
			res++;
		}
	}
	
	forn (i, n - 1)
		if (min(a[i], a[i + 1]) >= m)
			return res;
	
	int mn = 1e9;
	forn (i, n - 1) {
		int acu = 0;
		if (a[i] < m && a[i] == p[i])
			acu++;
		if (a[i + 1] < m && a[i + 1] == p[i + 1])
			acu++;
		mn = min(mn, res + acu);
	}
	
	return mn;
}

void main_() {
	cin >> n >> k;
	forn (i, n)
		cin >> p[i];
	
	int i = 1, j = 1e9, rep = 30;
	while (rep--) {
		int m = (i + j + 1) / 2;
		if (f(m) <= k) i = m;
		else j = m;
	}
	cout << i << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}