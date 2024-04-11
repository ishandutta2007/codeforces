#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

namespace SuffixArray {
	int n, len;
	string s;
	int sa[N], rnk[N], lcp[N];
	bool cmp(int u,int v) {
		if (rnk[u] ^ rnk[v]) {
			return rnk[u] < rnk[v];
		}
		u += len, v += len;
		return (u < n && v < n ? rnk[u] < rnk[v] : u > v);
	}
	void build(string t) {
		s = t;
		n = s.size();
		for (int i = 0; i < n; ++i) sa[i] = i;
		for (int i = 0; i < n; ++i) rnk[i] = s[i];
		for (len = 1; ; len <<= 1) {
			sort(sa, sa + n, cmp);
			vector<int> pre(n);
			for (int i = 1; i < n; ++i) {
				pre[i] = pre[i - 1] + cmp(sa[i - 1], sa[i]);
			}
			for (int i = 0; i < n; ++i) {
				rnk[sa[i]] = pre[i];
			}
			if (pre[n - 1] == n - 1) break;
		} 		
	}
};

using SuffixArray::sa;
using SuffixArray::build;

typedef long long ll;

ll sm[N];

int main() {
	ios_base::sync_with_stdio(false);
	
	string s; ll k;
	cin >> s >> k;
	int n = s.size();
	if (2 * k > (ll) n * (n + 1)) {
		cout << "No such line.\n";
		return 0;
	}
	build(s);
	for (int i = 0; i < n; ++i) {
		sm[i] = n - sa[i];
		if (i) sm[i] += sm[i - 1];
	}
	int l = 0, r = n - 1, len = 1;
	
	while (k) {
		int nl, nr;
		
		auto find = [&](char c, bool L) {
			int lw = l, hg = r;
			int ans = -1;
			while (lw <= hg) {
				int md = (lw + hg) >> 1;
				char cmd = sa[md] + len - 1 < n ? s[sa[md] + len - 1] : 'a' - 1;
				if (cmd > c) {
					hg = md - 1;
				} else if (cmd < c) {
					lw = md + 1;
				} else {
					ans = md;
					if (L) {
						hg = md - 1;
					} else {
						lw = md + 1;
					}
				}
			}
			return ans;
		};
		
		for (char c = 'a'; c <= 'z'; ++c) {
			nl = find(c, true);
			nr = find(c, false);
			
			if (nl == -1) {
				continue;
			}
			
			ll now = sm[nr];
			if (nl) now -= sm[nl - 1];
			now -= (ll) (nr - nl + 1) * (len - 1);
			
			if (now >= k) {
				l = nl;
				r = nr;
				break;
			} else {
				k -= now;
			}
		}
		
		++len;
		k -= min(k, (ll)(r - l + 1));
	}
	
	cout << s.substr(sa[l], len - 1) << '\n';
}