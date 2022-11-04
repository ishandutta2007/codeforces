
// Problem : C. Keshi Is Throwing a Party
// Contest : Codeforces - Codeforces Global Round 17
// URL : https://codeforces.com/contest/1610/problem/C
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

const int MX = 200005;
int n, a[MX], b[MX];

void main_() {
	cin >> n;
	
	forn (i, n)
		cin >> a[i] >> b[i];
		
	int l = 0, r = n, rep = 20;
	while (rep--) {
		int m = (l + r + 1) / 2, p = 0;
		
		forn (i, n)
			p += p <= b[i] && m - p - 1 <= a[i];
		
		if (p >= m) l = m;
		else r = m;
	}
	
	cout << l << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}