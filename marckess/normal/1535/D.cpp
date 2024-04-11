#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int k, q;
int st[1 << 20], mp[1 << 20];
char c[1 << 20];

void solve () {
	cin >> k;
	
	for (int i = (1 << k); i < (1 << (k + 1)); i++)
		st[i] = 1;
	
	for (int j = k, t = 1; j >= 1; j--)
		for (int i = 1; i <= (1 << (j - 1)); i++, t++)
			mp[t] = (1 << (j - 1)) + i - 1;
	
	for (int j = 1; j < (1 << k); j++) {
		int i = mp[j];
		
		cin >> c[i];
		
		if (c[i] != '1') st[i] += st[2 * i];
		if (c[i] != '0') st[i] += st[2 * i + 1];  	
	}
	
	cin >> q;
	while (q--) {
		int i;
		cin >> i;
		i = mp[i];
		
		cin >> c[i];
		
		while (i) {
			st[i] = 0;
			if (c[i] != '1') st[i] += st[2 * i];
			if (c[i] != '0') st[i] += st[2 * i + 1];
			
			i /= 2;
		}
		
		cout << st[1] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	
	return 0;
}