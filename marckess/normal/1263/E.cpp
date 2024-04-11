#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1000005;
int n, p[MX], in = 1;
int mx[4*MX], mn[4*MX], s[4*MX];
char c;

void build (int i, int j, int pos) {
	if (i == j) {
		p[i] = pos;
		return;
	}
	int m = (i + j) / 2;
	build(i, m, pos * 2);
	build(m + 1, j, pos * 2 + 1);
}

void update (int i, int k) {
	int pos = p[i];	
	mx[pos] = mn[pos] = s[pos] = k;
	pos /= 2;

	while (pos) {
		mx[pos] = mx[2 * pos] > s[2 * pos] + mx[2 * pos + 1] ? mx[2 * pos] : s[2 * pos] + mx[2 * pos + 1];
		mn[pos] = mn[2 * pos] < s[2 * pos] + mn[2 * pos + 1] ? mn[2 * pos] : s[2 * pos] + mn[2 * pos + 1];
		s[pos] = s[2 * pos] + s[2 * pos + 1];

		pos /= 2;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	build(1, n + 3, 1);

	forn (kk, n) {
		char op;
		cin >> op;

		if (op == '(') {
			update(in, 1);
		} else if (op == ')') {
			update(in, -1);
		} else if (op == 'L') {
			in = max(1, in - 1);
		} else if (op == 'R') {
			in++;
		} else {
			update(in, 0);
		}

		if (mn[1] >= 0 && s[1] == 0) {
			cout << mx[1] << " ";
		} else {
			cout << -1 << " ";
		}
	}

	cout << endl;

	return 0;
}