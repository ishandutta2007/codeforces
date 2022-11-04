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
string s;
int acu[MX][2], n;

ii find (int i, int j) {
	int x = acu[j][0] - (i ? acu[i - 1][0] : 0);
	int y = acu[n - 1][1] - (acu[j][1] - (i ? acu[i - 1][1] : 0));
	
	return {x, y};
}

void main_() {
	cin >> s;
	n = s.size();
	
	acu[0][0] = acu[0][1] = 0;
	forn (i, n) {
		if (i) {
			acu[i][0] = acu[i - 1][0];
			acu[i][1] = acu[i - 1][1];
		}
		acu[i][s[i] - '0']++;
	}
	
	int res = acu[n - 1][1];
	forn (i, n) {
		int l = 0, r = i, rep = 20;
		
		while (rep--) {
			int m = (l + r) / 2;
			auto [x, y] = find(m, i);
			
			if (x <= y) r = m;
			else l = m;
		}
		
		auto [x, y] = find(r, i);
		res = min(res, max(x, y));
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