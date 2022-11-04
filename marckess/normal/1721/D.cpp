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
int n, a[MX], b[MX];

void main_() {
	cin >> n;
	forn (i, n) cin >> a[i];
	forn (i, n) cin >> b[i];
	
	int res = 0;
	for (int j = 29; j >= 0; j--) {
		int aux = res | (1 << j);
		map<int, int> ma, mb;
		
		forn (i, n) {
			ma[a[i] & aux]++;
			mb[b[i] & aux]++;
		}
		
		int f = 1;
		for (const auto &it : ma)
			f &= it.se == mb[it.fi ^ aux];
		
		if (f)
			res = aux;
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