#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int maxN = (int)1e5 + 10;
struct pt {
	int x, y;
};
const int num[4] = {(int)1e9 + 7, (int)1e9 + 9, (int)1e9 + 23, (int)1e9 + 145};
bool cmp (pt a, pt b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
	return 1LL * a.x*(b.y-c.y)+ 1LL * b.x*(c.y-a.y)+ 1LL * c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
	return 1LL * a.x*(b.y-c.y)+1LL * b.x*(c.y-a.y)+1LL * c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> & a) {
	if (a.size() == 1)  return;
	sort (a.begin(), a.end(), &cmp);
	pt p1 = a[0],  p2 = a.back();
	vector<pt> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	a.clear();
	for (size_t i=0; i<up.size(); ++i)
		a.push_back (up[i]);
	for (size_t i=down.size()-2; i>0; --i)
		a.push_back (down[i]);
}
ll sum(ll a, ll b, ll mod) {
    ll s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
ll mult(ll a, ll b, ll mod) {
    return (a * b) % mod;
}
ll norm(ll a, ll mod) {
    return (a % mod + mod) % mod;
}
ll sub(ll a, ll b, ll mod) {
    ll s = a - b;
    if (s < 0) s += mod;
    return s;
}
void no() {
    cout << "NO";
    exit(0);
}
struct tup{
    int x, y;
    ll z;
};
ll all[2][2 * maxN][4];
ll prefhash[3 * maxN][4];
ll pws[2 * maxN][4];
main() {
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    int n, m;
    cin >> n >> m;
    vector < pt > a, b;
    a.resize(n);
    b.resize(m);
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i].x >> a[i].y;
    }
    for (int j = 0; j < b.size(); j++) {
        cin >> b[j].x >> b[j].y;
    }
    convex_hull(a);
    convex_hull(b);
    if (a.size() != b.size()) {
        no();
    }
    n = a.size();
    for (int i = 0; i < a.size(); i++) {
        pt a1 = a[i];
        pt a2 = a[(i + 1) % a.size()];
        pt a3 = a[(i + 2) % a.size()];
        int x1 = a1.x - a2.x;
        int y1 = a1.y - a2.y;
        int x2 = a3.x - a2.x;
        int y2 = a3.y - a2.y;
        ll len1 = (1LL * x1 * x1 + 1LL * y1 * y1);
        ll len2 = (1LL * x2 * x2 + 1LL * y2 * y2);
        ll scalar = 1LL * x1 * x2 + 1LL * y1 * y2;
        for (int j = 0; j < 4; j++) {
            ll mod = num[j];
            all[0][i][j] = sum(mult(2, norm(len1, mod), mod), sum(mult(3, norm(len2, mod), mod), mult(4, norm(scalar, mod), mod), mod), mod);
            all[0][n + i][j] = all[0][i][j];
        }
    }
    for (int i = 0; i < b.size(); i++) {
        pt a1 = b[i];
        pt a2 = b[(i + 1) % a.size()];
        pt a3 = b[(i + 2) % a.size()];
        int x1 = a1.x - a2.x;
        int y1 = a1.y - a2.y;
        int x2 = a3.x - a2.x;
        int y2 = a3.y - a2.y;
        ll len1 = (1LL * x1 * x1 + 1LL * y1 * y1);
        ll len2 = (1LL * x2 * x2 + 1LL * y2 * y2);
        ll scalar = 1LL * x1 * x2 + 1LL * y1 * y2;
        for (int j = 0; j < 4; j++) {
            ll mod = num[j];
            all[1][i][j] = sum(mult(2, norm(len1, mod), mod), sum(mult(3, norm(len2, mod), mod), mult(4, norm(scalar, mod), mod), mod), mod);
            all[1][n + i][j] = all[1][i][j];
        }
    }
    ll pt = rand() % 2242 + 10;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 4; j++) {
            ll mod = num[j];
            if (i == 0) pws[i][j] = 1;
            else pws[i][j] = mult(pws[i - 1][j], pt, mod);
        }
    }
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 4; j++) {
            ll mod = num[j];
            if (i == 0) prefhash[i][j] = all[0][0][j];
            else prefhash[i][j] = sum(prefhash[i - 1][j], mult(all[0][i][j], pws[i][j], mod), mod);
        }
    }
    int finalhash[4] = {0, 0, 0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            ll mod = num[j];
            if (i == 0) finalhash[j] = all[1][0][j];
            else finalhash[j] = sum(finalhash[j], mult(all[1][i][j], pws[i][j], mod), mod);
        }
    }
    for (int shift = 0; shift < n; shift++) {
        bool ok = true;
        for (int j = 0; j < 4; j++) {
            ll mod = num[j];
            int curhash;
            if (shift == 0) curhash = prefhash[shift + n - 1][j];
            else curhash = sub(prefhash[shift + n - 1][j], prefhash[shift - 1][j], mod);
            if (curhash == mult(finalhash[j], pws[shift][j], mod)) continue;
            ok = false;
            break;
        }
        if (ok) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}