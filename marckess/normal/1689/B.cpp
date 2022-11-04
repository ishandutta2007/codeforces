// Powered by CP Editor (https://cpeditor.org)

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

const int MX = 1005;
int n, p[MX], ex[MX], res[MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> p[i];
	memset(ex, 0, sizeof(ex));
	
	if (n == 1) {
		cout << -1 << endl;
		return;
	}
	
	forn (i, n) {
		int x = 0;
		forr (j, 1, n)
			if (!ex[j] && j != p[i]) {
				x = j;
				break;
			}
		
		if (!x) {
			forr (j, 1, n)
				if (!ex[j]) {
					x = j;
					break;
				}
		}
		
		ex[x] = 1;
		res[i] = x;
	}
	
	if (res[n - 1] == p[n - 1])
		swap(res[n - 1], res[n - 2]);
	
	forn (i, n)
		cout << res[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}