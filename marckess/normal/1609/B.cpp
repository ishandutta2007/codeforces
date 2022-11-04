
// Problem : B. William the Vigilant
// Contest : Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1609/problem/B
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

int n, q;
string s;

int f (int i) {
	if (i < 0 || i + 3 > n) return 0;
	return s.substr(i, 3) == "abc";
}

void main_() {
	cin >> n >> q >> s;
	
	int res = 0;
	forn (i, n)
		res += f(i);
	
	while (q--) {
		int i;
		char c;
		cin >> i >> c;
		i--;
		
		forn (j, 3) res -= f(i - j);
		s[i] = c;
		forn (j, 3) res += f(i - j);
		
		cout << res << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}