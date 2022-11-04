
// Problem : A. Linear Keyboard
// Contest : Codeforces - Codeforces Round #753 (Div. 3)
// URL : https://codeforces.com/contest/1607/problem/A
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

string s, t;
int pos[256];

void main_() {
	cin >> s >> t;
	forn (i, 26)
		pos[s[i]] = i;
	
	ll res = 0;
	forn (i, (int)t.size() - 1)
		res += abs(pos[t[i]] - pos[t[i + 1]]);
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