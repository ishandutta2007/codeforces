
// Problem : A. Balanced Substring
// Contest : Codeforces - Educational Codeforces Round 113 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1569/problem/A
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

void main_() {
	string s;
	int n;
	
	cin >> n >> s;
	
	forn (j, n)
		forn (i, j) {
			int a = 0, b = 0;
			for (int k = i; k <= j; k++)
				if (s[k] == 'a') a++;
				else b++;
			
			if (a == b) {
				cout << i + 1 << " " << j + 1 << endl;
				return;
			}
		}
	
	cout << -1 << " " << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}