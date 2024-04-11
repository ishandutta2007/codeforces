
// Problem : E. Robot on the Board 1
// Contest : Codeforces - Codeforces Round #753 (Div. 3)
// URL : https://codeforces.com/contest/1607/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

int n, m;
string s;

void main_() {
	cin >> n >> m >> s;
	
	int a = 0, b = 0, c = 0, d = 0;
	int x = 0, y = 0;
	for (char h : s) {
		if (h == 'U') x--;
		if (h == 'D') x++;
		if (h == 'L') y--;
		if (h == 'R') y++;
		
		int rx = 1 - a, ry = 1 - c;
		
		a = min(a, x);
		b = max(b, x);
		c = min(c, y);
		d = max(d, y);
		
		if (b - a + 1 > n || d - c + 1 > m) {
			cout << rx << " " << ry << endl;
			return;
		}
	}
	
	cout << 1 - a << " " << 1 - c << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}