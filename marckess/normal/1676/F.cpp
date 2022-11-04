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
int n, k, a[MX];

void main_() {
	cin >> n >> k;
	
	map<int, int> mp;
	forn (i, n) {
		cin >> a[i];
		mp[a[i]]++;
	}
	
	int act = 0, rl = -1, rr = -2;
	while (1) {
		auto it = mp.lower_bound(act);
		if (it == mp.end())
			break;
		act = it->fi;
		
		if (it->se < k) {
			act++;
			continue;
		}
		
		int ini = act, fin = act - 1;
		while (it != mp.end() && it->se >= k && it->fi == fin + 1) {
			fin++;
			it = mp.upper_bound(fin);
		}
		act = fin + 1;
		
		if (fin - ini + 1 > rr - rl + 1) {
			rl = ini;
			rr = fin;
		}
	}
	
	if (rl == -1) cout << -1 << endl;
	else cout << rl << " " << rr << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}