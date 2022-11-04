#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 500005;
int n, m, k, a[MX], p[MX], s[MX];

int parent (int a) { return a == p[a] ? a : p[a] = parent(p[a]); }
void join(int a, int b) {
	a = parent(a);
	b = parent(b);
	if (a == b) return;
	p[a] = b;
	s[b] += s[a];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(p, p+MX, 0);
	fill(s, s+MX, 1);
	
	cin >> n >> m;
	while (m--) {
		cin >> k;
		for (int i = 0; i < k; i++)
			cin >> a[i];
		for (int i = 1; i < k; i++)
			join(a[i-1], a[i]);
	}

	for (int i = 1; i <= n; i++)
		cout << s[parent(i)] << " ";
	cout << endl;

	return 0;
}