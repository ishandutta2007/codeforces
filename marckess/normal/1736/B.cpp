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
int n, a[MX];
map<int, int> mp[MX];

void main_() {
	cin >> n;
	
	forn (i, n) {
		cin >> a[i];
		
		mp[i].clear();
		int x = a[i];
		
		for (int j = 2; j * j <= x; j++)
			while (x % j == 0) {
				x /= j;
				mp[i][j]++;
			}
		
		if (x > 1)
			mp[i][x]++;
	}
	
	forr (i, 1, n - 2) {
		for (auto it : mp[i - 1])
			if (mp[i - 1][it.fi] > mp[i][it.fi] && mp[i][it.fi] < mp[i + 1][it.fi]) {
				cout << "NO" << endl;
				return;
			}
		
		for (auto it : mp[i * 1])
			if (mp[i - 1][it.fi] > mp[i][it.fi] && mp[i][it.fi] < mp[i + 1][it.fi]) {
				cout << "NO" << endl;
				return;
			}
		
		for (auto it : mp[i + 1])
			if (mp[i - 1][it.fi] > mp[i][it.fi] && mp[i][it.fi] < mp[i + 1][it.fi]) {
				cout << "NO" << endl;
				return;
			}
	}
	
	cout << "YES" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}