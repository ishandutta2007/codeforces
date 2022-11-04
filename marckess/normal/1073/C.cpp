#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, g, h, ox = 0, oy = 0;
string s;
int acu[256][MX];
int mp[256];
int mx[] = {0, 0, -1, 1};
int my[] = {1, -1, 0, 0};

bool esPos (int a, int b) {
	if (a > b) return ox == g && oy == h;
	int x = 0, y = 0;

	if (a) {
		x += acu['R'][a-1];
		x -= acu['L'][a-1];
		y += acu['U'][a-1];
		y -= acu['D'][a-1];
	}

	x += acu['R'][n-1] - acu['R'][b];
	x -= acu['L'][n-1] - acu['L'][b];
	y += acu['U'][n-1] - acu['U'][b];
	y -= acu['D'][n-1] - acu['D'][b];

	int k = abs(x-g) + abs(y-h);

	if (k > b - a + 1 || k % 2 != (b - a + 1) % 2) return 0;
	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	mp['D'] = 1;
	mp['L'] = 2;
	mp['R'] = 3;
	
	cin >> n >> s >> g >> h;

	if (abs(h) + abs(g) > n || (abs(h) + abs(g)) % 2 != n % 2) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < s.size(); i++) {
		if (i) acu['U'][i] = acu['U'][i-1];
		if (i) acu['D'][i] = acu['D'][i-1];
		if (i) acu['L'][i] = acu['L'][i-1];
		if (i) acu['R'][i] = acu['R'][i-1];
		acu[s[i]][i]++;
		ox += mx[mp[s[i]]];
		oy += my[mp[s[i]]];
	}

	int i = 0, j = n+1, rep = 20;
	while (rep--) {
		int m = (i+j)/2;
		bool f = 0;

		for (int k = 0; k + m - 1 < n; k++)
			f |= esPos(k, k+m-1);

		if (f) j = m;
		else i = m;
	}

	if (j == n+1) cout << -1 << endl;
	else cout << j << endl;

	return 0;
}