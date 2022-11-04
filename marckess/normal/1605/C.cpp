
// Problem : C. Dominant Character
// Contest : Codeforces - Codeforces Round #754 (Div. 2)
// URL : https://codeforces.com/contest/1605/problem/C
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

int n;
string s;

void main_() {
	cin >> n >> s;
	
	int res = 1e9;
	
	forn (i, n) {
		int a = 0, b = 0, c = 0;
		
		for (int j = i; j < min(n, i + 7); j++) {
			if (s[j] == 'a') a++;
			if (s[j] == 'b') b++;
			if (s[j] == 'c') c++;
			
			if (j > i && a > b && a > c)
				res = min(res, j - i + 1);
		}
	}
	
	if (res == 1e9) cout << -1 << endl;
	else cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}