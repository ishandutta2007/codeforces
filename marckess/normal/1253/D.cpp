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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, p[MX], mx[MX], res;

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	a = parent(a), b = parent(b);
	mx[a] = max(mx[a], mx[b]);
	p[b] = a;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(p, p+MX, 0);
	iota(mx, mx+MX, 0);	

	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		join(a, b);
		join(b, a);
	}

	for (int i = 1, j = 1; i <= n; i++) {
		if (parent(i) != parent(j)) {
			join(i, j);
			res++;
		}

		if (i == mx[parent(i)])
			j = i + 1;
	}

	cout << res << endl;

	return 0;
}