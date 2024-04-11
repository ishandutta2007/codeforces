#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 1000100
#define MOD 998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>


int main() {
	int t;
	int s1, s2, ss;
	int c[N];
	int d[N];
	int n, m, x, y, z;
	int h, v;
	int sz, sz2;
	bool aa[N];
	bool bb[N];
	vector<int>a;
	vector<int>b;
	vector<int>a1;
	vector<int>b1;
	vector<int>a2;
	vector<int>b2;
	vector<int>an;
	vector<int>bn;
	cin >> t;
	rep(tt, t) {
		a.clear();
		b.clear();
		cin >> n;
		s1 = 0;
		rep(i, n) {
			cin >> x;
			a.pb(x);
			s1 += x;
		}
		cin >> m;
		s2 = 0;
		rep(i, m) {
			cin >> x;
			b.pb(x);
			s2 += x;
		}
		if ((n != m) || (s1 % 2 == 1) || (s2 % 2 == 1)) {
			cout << "No" << endl;
		}
		else {
			sort(all(a));
			sort(all(b));
			rep(i, s1 + 1)c[i] = -2;
			c[0] = -1;
			ss = 0;
			s1 /= 2;
			rep(i, n) {
				rep3(j, ss, 0) {
					if (((c[j] + 1) >= 0) && ((c[j + a[i]] + 1) < 0))c[j + a[i]] = i;
				}
				ss += a[i];
				if (c[s1] >= 0)break;
			}
			rep(i, s2 + 1)d[i] = -2;
			d[0] = -1;
			ss = 0;
			s2 /= 2;
			rep(i, m) {
				rep3(j, ss, 0) {
					if (((d[j] + 1) >= 0) && ((d[j + b[i]] + 1) < 0))d[j + b[i]] = i;
				}
				ss += b[i];
				if (d[s2] >= 0)break;
			}
			if ((c[s1] >= 0) && (d[s2] >= 0)) {
				rep(i, n)aa[i] = true;
				a1.clear();
				a2.clear();
				x = s1;
				while (x > 0) {
					y = c[x];
					aa[y] = false;
					a1.pb(a[y]);
					x -= a[y];
				}
				rep(i, n)if (aa[i])a2.pb(a[i]);
				rep(i, m)bb[i] = true;
				b1.clear();
				b2.clear();
				x = s2;
				while (x > 0) {
					y = d[x];
					bb[y] = false;
					b1.pb(b[y]);
					x -= b[y];
				}
				rep(i, m)if (bb[i])b2.pb(b[i]);
				sort(all(a1), greater<int>());
				sort(all(a2), greater<int>());
				sort(all(b1));
				sort(all(b2));
				an.clear();
				bn.clear();
				sz = a1.size();
				sz2 = a2.size();
				if (sz > sz2)swap(a1, a2);
				sz = b1.size();
				sz2 = b2.size();
				if (sz < sz2)swap(b1, b2);

				sz = a1.size();
				rep(i, sz)an.pb(a1[i]);
				sz = a2.size();
				rep(i, sz)an.pb(-a2[i]);
				sz = b1.size();
				rep(i, sz)bn.pb(b1[i]);
				sz = b2.size();
				rep(i, sz)bn.pb(-b2[i]);
				x = 0;
				y = 0;
				cout << "Yes" << endl;
				rep(i, n) {
					x += an[i];
					cout << x << " " << y << endl;
					y += bn[i];
					cout << x << " " << y << endl;
				}
			}
			else {
				cout << "No" << endl;
			}
		}
	}
	return 0;
}