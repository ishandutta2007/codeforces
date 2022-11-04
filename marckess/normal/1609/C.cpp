
// Problem : C. Complex Market Analysis
// Contest : Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1609/problem/C
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
int n, e, a[MX], bs[MX];

void main_() {
	cin >> n >> e;
	forn (i, n)
		cin >> a[i];
	
	ll res = 0;
	forn (i, e) {
		int x = -1, y = -1;
		
		for (int j = i, k = 0; j < n; j += e, k++) {
			if (!bs[a[j]]) y = max(y, x), x = k;
			else if (a[j] > 1) y = k;
			
			if (x != -1)
				res += max(0, x - y);
		}
	}
	
	forn (i, n)
		if (!bs[a[i]])
			res--;
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	bs[0] = bs[1] = 1;
	forr (i, 2, MX - 1)
		if (!bs[i])
			for (int j = 2 * i; j < MX; j += i)
				bs[j] = 1;
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}