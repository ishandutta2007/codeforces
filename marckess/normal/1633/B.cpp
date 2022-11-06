
// Problem : B. Minority
// Contest : Codeforces - Educational Codeforces Round 122 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1633/problem/B
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

string s;

void main_() {
	cin >> s;
	int a = 0, b = 0, res = 0;
	
	for (int c : s) {
		if (c == '0') a++;
		else b++;
	}
	
	if (a != b) res = min(a, b);
	else {
		if (s[0] == '0') res = min(a - 1, b);
		else res = min(a, b - 1);
		
		if (s.back() == '0') res = min(a - 1, b);
		else res = min(a, b - 1);
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