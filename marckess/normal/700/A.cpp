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

const ld eps = 1e-12;
int n, k;
ld l, v1, v2;

bool leq (ld a, ld b) {
	return a < b || fabs(a-b) < eps;
}

bool esPos (ld mit) {
	ld t = 0, pos = 0;
	int acu = 0;

	while (acu < n) {
		acu += k;

		ld i = pos, j = l, m, temp, a, b;
		int rep = 80;
		while (rep--) {
			m = (i+j)/2;
			temp = (m - pos) / v2 + (l - m) / v1;
			if (leq(t+temp, mit)) j = m;
			else i = m;
		}

		temp = (j - pos) / v2 + (l - j) / v1;
		if (!leq(t+temp, mit)) return 0;
		t += (j - pos) / v2;
		pos = j;

		if (acu < n) {
			i = t, j = mit, rep = 80;
			while (rep--) {
				m = (i+j)/2;
				a = m * v1;
				b = pos - (m - t) * v2;
				if (leq(b, a)) j = m;
				else i = m;
			}
			t = j;
			pos = a;
			if (!leq(t, mit)) return 0;
		}
	}

	return leq(t, mit);
}

ld obtRes () {
	ld i = 0, j = l / v1 + eps, rep = 60;

	while (rep--) {
		ld m = (i+j)/2;
		if (esPos(m)) j = m;
		else i = m;
	}

	return j;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> n >> l >> v1 >> v2 >> k;
	cout << obtRes() << endl;

	return 0;
}