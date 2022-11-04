#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n, q, a[MX], l, r, x;
vi pos[MX];

int obtRes () {
	auto it = lower_bound(ALL(pos[x]), l);
	if (it == pos[x].end() || *it != l) return l;

	int i = 0, j = r-l+1, rep = 20, ind = it - pos[x].begin();
	while (rep--) {
		int m = (i+j)/2;
		if (ind + m >= pos[x].size() || pos[x][ind+m] != l+m)
			j = m;
		else
			i = m;
	}

	if (j == r-l+1) return -1;
	return j+l;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]].push_back(i);
	}

	while (q--) {
		cin >> l >> r >> x;
		cout << obtRes() << endl;
	}

	return 0;
}