// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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
int n, m, a[MX], b[MX], c[MX];

bool esPos (int t) {
	int f = m;
	
	forr (i, 1, n)
		c[i] = 0;
		
	forr (i, 1, n) {
		int d = min(b[i], t);
		f -= d;
		c[i] += d;
	}
	
	forr (i, 1, n) {
		int d = min((t - c[i]) / 2, f);
		f -= d;
		c[i] += 2 * d;
	}
	
	return f == 0;
}

void main_() {
	cin >> n >> m;
	
	forn (i, max(n, m) + 3) {
		b[i] = 0;
		c[i] = 0;
	}
	
	forn (i, m) {
		cin >> a[i];
		b[a[i]]++;
	}
	
	int i = 0, j = 2 * MX, rep = 20;
	while (rep--) {
		int m = (i + j) / 2;
		if (esPos(m)) j = m;
		else i = m;
	}
	cout << j << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}