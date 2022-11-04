
// Problem : B. Mocha and Red and Blue
// Contest : Codeforces - Codeforces Round #738 (Div. 2)
// URL : https://codeforces.com/contest/1559/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

int n;
string s, res;

void solve () {
	cin >> n >> s;
	
	for (int i = 0; i < n;) {
		if (s[i] == '?') {
			int j = i;
			while (j + 1 < n && s[j + 1] == '?')
				j++;
			
			int x = 0, y = 0;
			if (i) {
				if (s[i - 1] == 'B') x++;
				else y++;
			}
			
			if (j + 1 < n) {
				if ((j - i) % 2) {
					if (s[j + 1] == 'R') x++;
					else y++;
				} else {
					if (s[j + 1] == 'B') x++;
					else y++;
				}
			}
			
			string p;
			
			if (x < y) p = "BR";
			else p = "RB";
			
			for (int k = i; k <= j; k++)
				s[k] = p[(k - i) % 2];
			
			i = j + 1;
		} else {
			i++;
		}
	}
	
	cout << s << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}