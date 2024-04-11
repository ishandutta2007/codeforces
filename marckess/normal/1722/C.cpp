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
int n;
string s[3][MX];
map<string, int> mp;

void main_() {
	cin >> n;
	mp.clear();
	forn (i, 3)
	forn (j, n) {
		cin >> s[i][j];
		mp[s[i][j]]++;
	}
	
	vi res(3);
	forn (i, 3)
	forn (j, n) {
		int x = mp[s[i][j]];
		if (x == 1) res[i] += 3;
		else if (x == 2) res[i] += 1;
	}
	
	forn (i, 3) cout << res[i] << " "; cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}