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

const int MX = 200005;
int n, k, a[MX], b[MX];

void main_() {
	cin >> n >> k;
	forn (i, n) {
		cin >> a[i];
		b[i] = a[i];
	}
	
	sort(b, b + n);
	int x = 1, y = 1e9;
	
	int i = 0, j = 0;
	while (j < n) {
		ll _1 = j - i + 1;
		ll _0 = n - _1;
		if (_1 - _0 >= k)
			break;
		j++;
	}
	
	while (j < n) {
		if (b[j] - b[i] < y - x)
			x = b[i], y = b[j];
		i++, j++;
	}
	
	cout << x << " " << y << endl;
	int cn = 0;
	cout << 1 << " ";
	
	k--;
	forn (i, n) {
		if (!k) break;
		
		if (x <= a[i] && a[i] <= y)
			cn++;
		else
			cn--;
		
		if (cn == 1) {
			cout << i + 1 << endl;
			cout << i + 2 << " ";
			k--;
			cn = 0;
		}
	}
	cout << n << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}