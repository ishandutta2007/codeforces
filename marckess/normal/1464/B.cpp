#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n;
ll x, y, pre[MX][2], suf[MX][2], res, acu;
string s;

void insert (int i, int k, int f) {
	if (k) {
		acu += f * x * pre[i][0];
		acu += f * y * suf[i][0];
	} else {
		acu += f * y * pre[i][1];
		acu += f * x * suf[i][1];
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s >> x >> y;
	n = s.size();
	
	forn (i, n) {
		if (s[i] != '?')
			pre[i][s[i] - '0']++;
			
		if (i) {
			pre[i][0] += pre[i - 1][0];
			pre[i][1] += pre[i - 1][1];
		}
	}
	
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] != '?')
			suf[i][s[i] - '0']++;
		
		suf[i][0] += suf[i + 1][0];
		suf[i][1] += suf[i + 1][1];
	}
	
	forn (i, n)
		if (s[i] == '0')
			insert(i, 0, 1);
	
	int cn = 0, a, b;
	forn (i, n)
		if (s[i] == '?') {
			insert(i, 0, 1);
			cn++;
		}	
	res = acu;
	a = 0;
	b = cn;
	
	forn (i, n)
		if (s[i] == '?') {
			insert(i, 0, -1);
			insert(i, 1, 1);
			a++, b--;
			res = min(res, acu + y * a * b);
		}
	swap(a, b);
	
	forn (i, n)
		if (s[i] == '?') {
			insert(i, 1, -1);
			insert(i, 0, 1);
			a++, b--;
			res = min(res, acu + x * a * b);
		}
	
	cout << res << endl;
	
	return 0;
}