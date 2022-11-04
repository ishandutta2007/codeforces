#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

map< int, map<int, int> > p;
int n, x[100005], y[100005], M = 1e9+9;
bitset<100005> es;

priority_queue<int> mx;
priority_queue<int, vi, greater<int> > mn;

ll pot (ll b, int p, int m) {
	ll res = 1;

	while (p) {
		if (p & 1) {
			res *= b;
			res %= m;
		}

		b *= b;
		b %= m;
		p /= 2;
	}

	return res;
}

bool exis (int x, int y) {
	map<int, map<int, int> >::iterator v = p.find(x);
	if (v == p.end())
		return false;
	map<int, int>::iterator u = v->se.find(y);
	if (u == v->se.end())
		return false;
	return es[u->se];
}

bool esPos (int x, int y) {
	bool res = true;

	for (int i = -1; i <= 1; i++)
		if (exis(x+i, y+1)) {
			bool f = false;
			for (int j = -1; j <= 1; j++) {
				if (i != -j)
					f |= exis(x+j+i, y);
			}
			res &= f;
		}

	return res;
}

void init () {
	for (int i = 0; i < n; i++)
		if (esPos(x[i], y[i])) {
			mx.push(i);
			mn.push(i);
		}
}

ll obtRes () {
	init();
	bool t = true;
	int i, pt = n - 1;
	ll res = 0;

	while (es.count()) {
		if (t) {
			while (!es[(i = mx.top())] || !esPos(x[i], y[i]))
				mx.pop();
			mx.pop();
		} else {
			while (!es[(i = mn.top())] || !esPos(x[i], y[i]))
				mn.pop();
			mn.pop();
		}

		res += i * pot(n, pt, M);
		res %= M;

		es[i] = 0;
		if (y) {
			for (int j = -1; j <= 1; j++) {
				if (exis(x[i]+j, y[i]-1) && esPos(x[i]+j, y[i]-1)) {
					int xd = p[x[i]+j][y[i]-1];

					mx.push(xd);
					mn.push(xd);
				}
			}
		}

		t = !t;
		pt--;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		p[x[i]][y[i]] = i;
		es[i] = 1;
	}

	cout << obtRes() << endl;

	return 0;
}