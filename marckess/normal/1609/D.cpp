
// Problem : D. Social Network
// Contest : Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1609/problem/D
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

const int MX = 1005;
int n, d, p[MX], cn[MX];

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void main_() {
	cin >> n >> d;
	iota(p, p + MX, 0);
	
	int f = 1;
	while (d--) {
		int x, y;
		cin >> x >> y;
		
		if (parent(x) != parent(y)) p[parent(x)] = parent(y);
		else f++;
		
		memset(cn, 0, sizeof(cn));
		forr (i, 1, n)
			cn[parent(i)]++;
		
		vi v;
		forr (i, 1, n)
			if (cn[i])
				v.pb(cn[i]);
		
		int res = 0;
		sort(all(v), greater<int>());
		forn (i, min(f, (int)v.size()))
			res += v[i];
		
		cout << res - 1 << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		main_();
	
	return 0;
}