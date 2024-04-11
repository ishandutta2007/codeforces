
// Problem : C. Omkar and Determination
// Contest : Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL : https://codeforces.com/contest/1586/problem/C
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

const int MX = 1000005;
int n, m, to[MX];
string a[MX];

void main_() {
	cin >> n >> m;
	
	forn (i, n)
		cin >> a[i];
	
	to[0] = -1;
	forn (j, m) {
		if (!j) continue;
		
		to[j] = to[j - 1];
		forn (i, n)
			if (i && a[i - 1][j] == 'X' && a[i][j - 1] == 'X')
				to[j] = j - 1;
	}
	
	int q;
	cin >> q;
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		
		if (l <= to[r]) cout << "NO" << endl;
		else cout << "YES" << endl;
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