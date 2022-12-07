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
int n, x, res[MX], ex[MX];

void main_() {
	cin >> n >> x;
	forr (i, 1, n) {
		ex[i] = 0;
		res[i] = 0;
	}
	
	res[n] = 1;
	res[1] = x;
	ex[1] = ex[x] = 1;
	
	for (int i = n - 1; i > 1; i--) {
		vi v;
		
		for (int j = i; j <= n; j += i)
			if (!ex[j])
				v.pb(j);
		
		if (!v.size()) {
			cout << -1 << endl;
			return;
		}
		
		if (v.size() == 1) {
			res[i] = v[0];
			ex[v[0]] = 1;
		}
	}
	
	for (int i = 2; i < n; i++) {
		if (res[i]) continue;
		vi v;
		
		for (int j = i; j <= n; j += i)
			if (!ex[j])
				v.pb(j);
		
		if (!v.size()) {
			cout << -1 << endl;
			return;
		}
		
		res[i] = v[0];
		ex[v[0]] = 1;
	}
	
	forr (i, 1, n)
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