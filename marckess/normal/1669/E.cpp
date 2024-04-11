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

const int MX = 100005;
int n, adj[256][256];

void main_() {
	cin >> n;
	memset(adj, 0, sizeof(adj));
	while (n--) {
		char x, y;
		cin >> x >> y;
		adj[x][y]++;
	}
	
	ll res = 0;
	for (int i = 'a'; i <= 'k'; i++) {
		ll acu = 0;
		for (int j = 'a'; j <= 'k'; j++) {
			res += acu * adj[i][j];
			acu += adj[i][j];
		}
		
		acu = 0;
		for (int j = 'a'; j <= 'k'; j++) {
			res += acu * adj[j][i];
			acu += adj[j][i];
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