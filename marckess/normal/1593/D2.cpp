
// Problem : D2. Half of Same
// Contest : Codeforces - Codeforces Round #748 (Div. 3)
// URL : https://codeforces.com/contest/1593/problem/D2
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

const int MX = 44;
int n, a[MX];

int esPos (int i, int k) {
	int cn = 0, ini = a[i];
	while (i < n)
		cn += (a[i++] - ini) % k == 0;
	return 2 * cn >= n;
}

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	sort(a, a + n);
	
	int res = 0;
	
	forn (i, n) {
		int cn = 0;
		forn (j, n)
			cn += a[i] == a[j];
		
		if (2 * cn >= n) {
			cout << -1 << endl;
			return;
		}
		
		for (int j = i; j < n; j++) {
			if (a[i] == a[j])
				continue;
			
			int x = a[j] - a[i];
			for (int k = 1; k * k <= x; k++)
				if (x % k == 0) {
					if (esPos(i, k)) res = max(res, k);
					if (esPos(i, x / k)) res = max(res, x / k);
				}
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