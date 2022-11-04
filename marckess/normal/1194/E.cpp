#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;
 
const int MX = 5005;
struct Seg {
	int x1, x2, y1, y2;
	Seg(){}
	Seg(int _x1, int _y1, int _x2, int _y2) {
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
	}
	bool operator < (const Seg& ot) const {
		return y2 < ot.y2;
	}
	string str() {
		return to_string(x1);
	}
};
int n, ft[2*MX];
vector<Seg> h, v;

void update (int i, int k) {
	i += MX;
	while (i < 2 * MX) {
		ft[i] += k;
		i += i & -i;
	}
}

int query (int i) {
	i += MX;
	int s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

int query(int a, int b) {
	return query(b) - query(a - 1);
}

bool inter (Seg& h, Seg& v) {
	return h.x1 <= v.x1 && v.x1 <= h.x2
		&& v.y1 <= h.y1 && h.y1 <= v.y2;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	while (n--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2) v.pb(x1, y1, x2, y2);
		else h.pb(x1, y1, x2, y2);
	}

	sort(all(h));
	sort(all(v));
	ll res = 0;

	for (int i = 0; i < h.size(); i++) {
		memset(ft, 0, sizeof(ft));

		for (int j = 0; j < v.size(); j++) {
			if (inter(h[i], v[j])) {
				update(v[j].x1, 1);
			}
		}

		for (int j = 0, k = i + 1; k < h.size(); k++) {
			while (j < v.size() && v[j].y2 < h[k].y2) {
				if (inter(h[i], v[j]))
					update(v[j].x1, -1);
				j++;
			}

			ll x = query(h[k].x1, h[k].x2);
			res += x * (x - 1) / 2;
		}
	}

	cout << res << endl;

	return 0;
}