#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = uint64_t;

using namespace std;

struct point {
	int x, y;
	int n, c;
	point() {
		x = y = n = c = 0;
	}
	point(ll X, ll Y) {
		x = X, y = Y;
		n = c = 0;
	}
	point operator-(point a) {
		return point(x - a.x, y - a.y);
	}
	bool operator<(point a) {
		return make_pair(x, y) < make_pair(a.x, a.y);
	}
	ll operator*(point a) {
		return x * a.y - y * a.x;
	}
};

const int MX = 6100;

int n, m;

int tmp[MX];
vector<pair<int, int>> ed;
point gp;


bool bad(point a, point b, point c) {
	return (b - a) * (c - a) <= 0;
}

int fl[MX];
vector<int> st;

void run(vector<point> &vv) {
	if (vv.size() < 2)
		return;
	if (vv.size() == 2) {
		if (vv[0].c == -1)
			ed.emplace_back(vv[1].n, vv[0].n);
		else
			ed.emplace_back(vv[0].n, vv[1].n);
		return;
	}
	for (int i = 1; i < vv.size(); ++i) {
		if (vv[i] < vv[0])
			swap(vv[i], vv[0]);
	}
	sort(vv.begin() + 1, vv.end(), [&] (point a, point b) {
			return (a - vv[0]) * (b - vv[0]) > 0;
			});
	st.clear();
	for (int i = 0; i < vv.size(); ++i) {
		while (st.size() >= 2 && bad(vv[st[st.size() - 2]], vv[st[st.size() - 1]], vv[i]))
			st.pop_back();
		st.push_back(i);
	}
	memset(fl, 0, sizeof(fl[0]) * vv.size());
	int ch = 0;
	for (int i = 0; i + 1 < st.size(); ++i) {
		int a = st[i];
		int b = st[i + 1];
		if (fl[a] || fl[b])
			continue;
		if ((vv[a].c == -1) == (vv[b].c == -1))
			continue;
		if (vv[a].c == -1)
			swap(a, b);
		ch = 1;
		if (vv[a].c == 1) {
			--vv[a].c;
			fl[a] = 1;
			ed.emplace_back(vv[a].n, vv[b].n);
		}
		else {
			--vv[a].c;
			fl[b] = 1;
			ed.emplace_back(vv[a].n, vv[b].n);
		}
	}
	if (!ch) {
		for (int i: st)
			fl[i] = 1;
		for (int i = 0; i < vv.size(); ++i) {
			if (fl[i])
				continue;
			if (vv[i].c == 1)
				continue;
			swap(vv[i], vv[0]);
			break;
		}
		point tmp = vv[0];
		vv.erase(vv.begin());

		sort(vv.begin(), vv.end(), [&] (point a, point b) {
				a = a - tmp;
				b = b - tmp;
				if (a.y >= 0 && b.y < 0)
				return true;
				if (a.y < 0 && b.y >= 0)
				return false;
				return a * b > 0;
				});
		int n = vv.size();
		for (int i = 0; i < n; ++i)
			vv.push_back(vv[i]);
		int now = 0;
		int bal = 0;
		vector<point> v1, v2;
		for (int i = 0; i < n; ++i) {
			while (now < i + n && (vv[i] - tmp) * (vv[now] - tmp) >= 0) {
				if (vv[now].c == -1)
					++bal;
				else
					bal += 1 - vv[now].c;
				++now;
			}
			if (vv[i].c == -1) {
				if (tmp.c == -1 && bal == 0) {
					v1.push_back(tmp);
					v2.push_back(tmp);
					for (int j = i; j < now; ++j)
						v1.push_back(vv[j]);
					for (int j = now; j < i + n; ++j)
						v2.push_back(vv[j]);
					return run(v1), run(v2);
				}
				else if (tmp.c != -1 && bal - 1 >= 0 && bal - (tmp.c - 1) <= 0) {
					point tmp1 = tmp;
					tmp1.c = bal;
					tmp.c -= bal;
					v1.push_back(tmp1);
					v2.push_back(tmp);
					for (int j = i; j < now; ++j)
						v1.push_back(vv[j]);
					for (int j = now; j < i + n; ++j)
						v2.push_back(vv[j]);
					vv.clear();
					vv.shrink_to_fit();
					return run(v1), run(v2);
				}
			}
			else {
				int pr = bal - 1 + vv[i].c;
				if (tmp.c == -1) {
					if (pr >= 0 && bal <= 0) {
						int go = -bal;
						point tmp1 = vv[i];
						point tmp2 = vv[i];
						tmp1.c -= go;
						tmp2.c = go + 1;
						ed.emplace_back(tmp1.n, tmp.n);
						--tmp1.c;
						--tmp2.c;
						if (tmp1.c == 0)
							v1.push_back(tmp);
						else
							v1.push_back(tmp1);
						if (tmp2.c == 0)
							v2.push_back(tmp);
						else
							v2.push_back(tmp2);

						for (int j = i; j < now - 1; ++j)
							v1.push_back(vv[j + 1]);
						for (int j = now; j < i + n; ++j)
							v2.push_back(vv[j]);
						vv.clear();
						vv.shrink_to_fit();
						return run(v1), run(v2);
					}
				}
				else {
					int dw = pr;
					int up = 1 - pr - (1 - tmp.c) - (1 - vv[i].c);
					int a = tmp.c;
					int b = vv[i].c;
					if (dw + (1 - b) - 1 >= 0 && dw + (1 - b) - (a - 1) <= 0) {
						int go = dw + (1 - b);
						point tmp1 = tmp;
						tmp1.c = go;
						point tmp2 = tmp;
						tmp2.c -= go;
						v1.push_back(tmp1);
						v2.push_back(tmp2);
						v1.push_back(vv[i]);
						for (int j = i; j < now - 1; ++j)
							v1.push_back(vv[j + 1]);
						for (int j = now; j < i + n; ++j)
							v2.push_back(vv[j]);
						vv.clear();
						vv.shrink_to_fit();
						return run(v1), run(v2);
					}
					else if (up + (1 - b) - 1 >= 0 && up + (1 - b) - (a - 1) <= 0) {
						int go = up + (1 - b);
						point tmp1 = tmp;
						tmp1.c = go;
						point tmp2 = tmp;
						tmp2.c -= go;
						v1.push_back(tmp1);
						v2.push_back(tmp2);
						v1.push_back(vv[i]);
						for (int j = i; j < now - 1; ++j)
							v2.push_back(vv[j + 1]);
						for (int j = now; j < i + n; ++j)
							v1.push_back(vv[j]);
						vv.clear();
						vv.shrink_to_fit();
						return run(v1), run(v2);
					}
					else if (dw + (1 - a) - 1 >= 0 && dw + (1 - a) - (b - 1) <= 0) {
						int go = dw + (1 - a);
						point tmp1 = vv[i];
						tmp1.c = go;
						point tmp2 = vv[i];
						tmp2.c -= go;
						v1.push_back(tmp1);
						v2.push_back(tmp2);
						v1.push_back(tmp);
						for (int j = i; j < now - 1; ++j)
							v1.push_back(vv[j + 1]);
						for (int j = now; j < i + n; ++j)
							v2.push_back(vv[j]);
						vv.clear();
						vv.shrink_to_fit();
						return run(v1), run(v2);
					}
					else if (up + (1 - a) - 1 >= 0 && up + (1 - a) - (b - 1) <= 0) {
						int go = up + (1 - a);
						point tmp1 = vv[i];
						tmp1.c = go;
						point tmp2 = vv[i];
						tmp2.c -= go;
						v1.push_back(tmp1);
						v2.push_back(tmp2);
						v1.push_back(tmp);
						for (int j = i; j < now - 1; ++j)
							v2.push_back(vv[j + 1]);
						for (int j = now; j < i + n; ++j)
							v1.push_back(vv[j]);
						vv.clear();
						vv.shrink_to_fit();
						return run(v1), run(v2);
					}
				}
			}
			if (vv[i].c == -1) {
				bal -= 1;
			}
			else {
				bal -= 1 - vv[i].c;
			}
		}
		now = 0;
		bal = 0;
		reverse(vv.begin(), vv.end());
		for (int i = 0; i < n; ++i) {
			while (now < i + n && (vv[i] - tmp) * (vv[now] - tmp) <= 0) {
				if (vv[now].c == -1)
					++bal;
				else
					bal += 1 - vv[now].c;
				++now;
			}
			if (vv[i].c == -1) {
				if (tmp.c == -1 && bal == 0) {
					v1.push_back(tmp);
					v2.push_back(tmp);
					for (int j = i; j < now; ++j)
						v1.push_back(vv[j]);
					for (int j = now; j < i + n; ++j)
						v2.push_back(vv[j]);
					return run(v1), run(v2);
				}
				else if (tmp.c != -1 && bal - 1 >= 0 && bal - (tmp.c - 1) <= 0) {
					point tmp1 = tmp;
					tmp1.c = bal;
					tmp.c -= bal;
					v1.push_back(tmp1);
					v2.push_back(tmp);
					for (int j = i; j < now; ++j)
						v1.push_back(vv[j]);
					for (int j = now; j < i + n; ++j)
						v2.push_back(vv[j]);
					vv.clear();
					vv.shrink_to_fit();
					return run(v1), run(v2);
				}
			}
			else {
				int pr = bal - 1 + vv[i].c;
				if (tmp.c == -1) {
					if (pr >= 0 && bal <= 0) {
						int go = -bal;
						point tmp1 = vv[i];
						point tmp2 = vv[i];
						tmp1.c -= go;
						tmp2.c = go + 1;
						ed.emplace_back(tmp1.n, tmp.n);
						--tmp1.c;
						--tmp2.c;
						if (tmp1.c == 0)
							v1.push_back(tmp);
						else
							v1.push_back(tmp1);
						if (tmp2.c == 0)
							v2.push_back(tmp);
						else
							v2.push_back(tmp2);

						for (int j = i; j < now - 1; ++j)
							v1.push_back(vv[j + 1]);
						for (int j = now; j < i + n; ++j)
							v2.push_back(vv[j]);
						vv.clear();
						vv.shrink_to_fit();
						return run(v1), run(v2);
					}
				}
				else {
					int dw = pr;
					int up = 1 - pr - (1 - tmp.c) - (1 - vv[i].c);
					int a = tmp.c;
					int b = vv[i].c;
					if (dw + (1 - b) - 1 >= 0 && dw + (1 - b) - (a - 1) <= 0) {
						int go = dw + (1 - b);
						point tmp1 = tmp;
						tmp1.c = go;
						point tmp2 = tmp;
						tmp2.c -= go;
						v1.push_back(tmp1);
						v2.push_back(tmp2);
						v1.push_back(vv[i]);
						for (int j = i; j < now - 1; ++j)
							v1.push_back(vv[j + 1]);
						for (int j = now; j < i + n; ++j)
							v2.push_back(vv[j]);
						vv.clear();
						vv.shrink_to_fit();
						return run(v1), run(v2);
					}
					else if (up + (1 - b) - 1 >= 0 && up + (1 - b) - (a - 1) <= 0) {
						int go = up + (1 - b);
						point tmp1 = tmp;
						tmp1.c = go;
						point tmp2 = tmp;
						tmp2.c -= go;
						v1.push_back(tmp1);
						v2.push_back(tmp2);
						v1.push_back(vv[i]);
						for (int j = i; j < now - 1; ++j)
							v2.push_back(vv[j + 1]);
						for (int j = now; j < i + n; ++j)
							v1.push_back(vv[j]);
						vv.clear();
						vv.shrink_to_fit();
						return run(v1), run(v2);
					}
					else if (dw + (1 - a) - 1 >= 0 && dw + (1 - a) - (b - 1) <= 0) {
						int go = dw + (1 - a);
						point tmp1 = vv[i];
						tmp1.c = go;
						point tmp2 = vv[i];
						tmp2.c -= go;
						v1.push_back(tmp1);
						v2.push_back(tmp2);
						v1.push_back(tmp);
						for (int j = i; j < now - 1; ++j)
							v1.push_back(vv[j + 1]);
						for (int j = now; j < i + n; ++j)
							v2.push_back(vv[j]);
						vv.clear();
						vv.shrink_to_fit();
						return run(v1), run(v2);
					}
					else if (up + (1 - a) - 1 >= 0 && up + (1 - a) - (b - 1) <= 0) {
						int go = up + (1 - a);
						point tmp1 = vv[i];
						tmp1.c = go;
						point tmp2 = vv[i];
						tmp2.c -= go;
						v1.push_back(tmp1);
						v2.push_back(tmp2);
						v1.push_back(tmp);
						for (int j = i; j < now - 1; ++j)
							v2.push_back(vv[j + 1]);
						for (int j = now; j < i + n; ++j)
							v1.push_back(vv[j]);
						vv.clear();
						vv.shrink_to_fit();
						return run(v1), run(v2);
					}
				}
			}
			if (vv[i].c == -1) {
				bal -= 1;
			}
			else {
				bal -= 1 - vv[i].c;
			}
		}
		assert(false);
	}
	else {
		vector<point> tmp;
		for (int i = 0; i < vv.size(); ++i) {
			if (fl[i] == 0)
				tmp.push_back(vv[i]);
		}
	//	vv.clear();
	//	vv.shrink_to_fit();
		return run(tmp);
	}
}

bool cross(point a, point b, point c, point d) {
	auto sgn = [] (ll x) {return (x > 0) - (x < 0);};
	if (sgn((b - a) * (c - a)) == sgn((b - a) * (d - a)))
		return 0;
	if (sgn((d - c) * (b - c)) == sgn((d - c) * (a - c)))
		return 0;
	return 1;
}

void checker(int n, int m, vector<point> vv, vector<pair<int, int>> ed) {
	for (auto p: ed) {
		assert(p.first >= 0 && p.first < m);
		assert(p.second >= 0 && p.second < n);
		assert(vv[n + p.first].c > 0);
		--vv[n + p.first].c;
	}
	for (int i = n; i < n + m; ++i)
		assert(vv[i].c == 0);
	for (int i = 0; i < ed.size(); ++i)
		for (int j = i + 1; j < ed.size(); ++j) {
			if (ed[i].first == ed[j].first)
				continue;
			if (ed[i].second == ed[j].second)
				continue;
			assert(!cross(vv[n + ed[i].first], vv[ed[i].second], vv[n + ed[j].first], vv[ed[j].second]));
		}
}

void solve() {
	ed.clear();
	cin >> n >> m;
	vector<point> vv;
	for (int i = 0; i < m; ++i)
		cin >> tmp[i];
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		point t;
		t.x = x, t.y = y;
		t.c = -1;
		t.n = i;
		vv.push_back(t);
	}
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		point t;
		t.x = x, t.y = y;
		t.c = tmp[i];
		t.n = i;
		vv.push_back(t);
	}
#ifdef BZ
	for (int i = 0; i < n + m; ++i)
		for (int j = i + 1; j < n + m; ++j)
			for (int k = j + 1; k < n + m; ++k) {
				if ((vv[j] - vv[i]) * (vv[k] - vv[i]) == 0) {
					return;
				}
			}
#endif
	vector<point> tmp = vv;
	run(vv);
	cout << "YES\n";
	for (int i = 0; i < ed.size(); ++i) {
		cout << ed[i].first + 1 << " " << ed[i].second + 1 << "\n";
	}
	checker(n, m, tmp, ed);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i)
		solve();
	return 0;
}