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

const int MX = 200005;
int n, k, u[MX];
map<int, int> ini, fin;

void main_() {
	cin >> n >> k;
	ini.clear(), fin.clear();
	forn (i, n) {
		cin >> u[i];
		if (!ini.count(u[i])) ini[u[i]] = i;
		fin[u[i]] = i;
	}
	
	while (k--) {
		int a, b;
		cin >> a >> b;
		if (!ini.count(a) || !fin.count(b) || ini[a] > fin[b]) cout << "NO" << endl;
		else cout << "YES" << endl;
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