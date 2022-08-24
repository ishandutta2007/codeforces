#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 2100;

int s0[MAXN];
int s1[MAXN];
int s2[MAXN];
int pl[MAXN];
int c0, c1, c2;
vector<pair<int, int> > vv;
int a, b;
int n;

void ex() {
	cout << "NO\n";
	exit(0);
}

void checks2() {
	for (int i = 0; i < c2; ++i) {
		if (s2[i] != n - i - 1)
			ex();
	}
}

void mv0(int x) {
	if (x == 0)
		return;
	vv.push_back(make_pair(1, x));
	for (int i = c0 - x; i < c0; ++i)
		s1[c1++] = s0[i], pl[s0[i]] = 1;
	c0 -= x;
}
vector<int> vp;

int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; ++i)
		scanf("%d", s0 + i), --s0[i];
	reverse(s0, s0 + n);
	c0 = n;
	c1 = 0;
	c2 = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (pl[i] == 2)
			continue;
		if (pl[i] == 1) {
			for (int j = 0; j < c1; ++j) {
				if (s1[j] == i) {
					if (c1 - j > b)
						ex();
					vv.push_back(make_pair(2, c1 - j));
					for (int k = j; k < c1; ++k)
						s2[c2++] = s1[k], pl[s1[k]] = 2;;
					c1 = j;
					checks2();
					break;
				}
			}
		}
		else {
			int pos = -1;
			for (int j = 0; j < c0; ++j)
				if (s0[j] == i) {
					pos = j;
					break;
				}
			int fl = 1;
			while (fl) {
				fl = 0;
				int lst = -1;
				if (c1)
					lst = s1[c1 - 1];
				for (int j = pos + 1; j < c0; ++j) {
					if (s0[j] == lst - 1) {
						if (c0 - j > a)
							ex();
						vv.push_back(make_pair(1, c0 - j));
						for (int k = j; k < c0; ++k)
							s1[c1++] = s0[k], pl[s0[k]] = 1;
						fl = 1;
						c0 = j;
						break;
					}
				}
			}
			int mx = -1;
			for (int j = 0; j < c1; ++j)
				mx = max(mx, s1[j]);
			int mn = n;
			for (int j = pos; j < c0; ++j)
				mn = min(mn, s0[j]);
			if (mn < mx)
				ex();
			for (int j = c0 - 1; j > pos; --j) {
				if (j == pos + 1 || s0[j] < s0[j - 1] - 1) {
					vp.clear();
					for (int k = c0 - 1; k >= j; --k)
						if (k == c0 - 1 || s0[k + 1] > s0[k])
							vp.push_back(k);
					vp.push_back(j - 1);
					if ((int)vp.size() == 2) {
						int nd = c0 - j;
						while (nd) {
							int go = min(min(a, b), nd);
							mv0(go);
							nd -= go;
						}
						continue;
					}
					if ((int)vp.size() == 3 && s0[vp[0]] - 1 == s0[j]) {
						int len = c0 - j;
						int l2 = vp[0] - vp[1];
						if (l2 <= a && len - l2 <= a && len <= b) {
							mv0(l2);
							mv0(len - l2);
							continue;
						}
						int fl = 0;
						for (int k = 0; k < len; ++k) {
							if (k <= a && (len - k) <= a && abs(k - l2) <= b && len - abs(k - l2) <= b) {
								fl = 1;
								mv0(k);
								mv0(len - k);
								break;
							}
						}
						if (fl)
							continue;
					}
					for (int k = 0; k < (int)vp.size() - 1; ++k) {
						if (vp[k] - vp[k + 1] > a)
							ex();
					}
					int fl = 0;
					for (int k = 0; k < (int)vp.size() - 2; ++k) {
						if (s0[vp[k]] - 1 != s0[vp[k + 2] + 1]) {
							fl = 1;
							break;
						}
					}
					if (!fl && c0 - j <= b) {
						for (int k = 0; k < (int)vp.size() - 1; ++k)
							mv0(vp[k] - vp[k + 1]);
					}
					else {
						if (c0 - j > a)
							ex();
						mv0(c0 - j);
					}
				}
			}
			mv0(1);
			vv.push_back(make_pair(2, 1));
			s2[c2++] = s1[c1 - 1];
			pl[s1[c1 - 1]] = 2;
			--c1;
		}

	}
	cout << "YES\n";
	cout << vv.size() << "\n";
	for (int i = 0; i < (int)vv.size(); ++i) {
		cout << vv[i].first << " " << vv[i].second << "\n";
	}
	return 0;
}