
// Problem : C. Make Them Equal
// Contest : Codeforces - Codeforces Round #747 (Div. 2)
// URL : https://codeforces.com/contest/1594/problem/C
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
char c;

void main_() {
	cin >> n >> c >> s;
	
	int f = 1;
	for (char h : s)
		f &= c == h;
	
	if (f) {
		cout << 0 << endl;
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		f = 1;
		for (int j = i; j <= n; j += i)
			f &= s[j - 1] == c;
		
		if (f) {
			cout << 1 << endl << i << endl;
			return;
		}
	}
	
	cout << 2 << endl;
	cout << n - 1 << " " << n << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}