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

const int MX = 100005;
int n;
char s[MX];

int p[MX], t[MX], a = -1, b = -1, res = 0;

int parent (int a) {
	return p[a] == a ? a : p[a] = parent(p[a]);
}

void joint (int a, int b) {
	a = parent(a), b = parent(b);
	if (a == b) return;

	p[a] = b;
	t[b] += t[a];
}

int solve (int i, int a) {
	if (parent(a) != parent(i-1) 
		&& parent(a) != parent(i+1)) {
		return t[parent(i-1)] + t[parent(i+1)] + 1;
	}

	return t[parent(i-1)] + t[parent(i+1)];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(p, p+MX, 0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> s[i];

		if (s[i] == 'G') {
			t[i] = 1;
			
			if (a == -1) a = i;
			b = i;

			if (s[i-1] == 'G') 
				joint(i-1, i);

			res = max(res, t[parent(i)]);
		}
	}

	if (a == -1) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		if (s[i] == 'S') {
			res = max(res, solve(i, a));
			res = max(res, solve(i, b));
		}
	}

	cout << res << endl;

	return 0;
}