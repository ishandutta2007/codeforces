#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

struct segment_tree{
	int n;
	vector<int> st;

	segment_tree(vi data){
		n = (int)data.size();
		st = vi(4 * n);

		build(1, 0, n, data);
	}

	void build(int p, int b, int e, vi &d){
		assert(p < 4 * n);
		if (b + 1 == e) st[p] = d[b];
		else{
			int m = (b + e) >> 1, l = p << 1, r = l | 1;
			build(l, b, m, d);
			build(r, m, e, d);
			st[p] = min(st[l], st[r]);
		}
	}

	int query(int p, int b, int e, int x, int v){
		assert(p < 4 * n);

		if (b + 1 == e){
			if (st[p] < v) return b;
			else return -1;
		}
		else{
			int m = (b + e) >> 1, l = p << 1, r = l | 1;

			int ans = -1;
			if (x < m){
				if (st[l] < v) ans = query(l, b, m, x, v);
				if (ans > -1) return ans;
			}
			return query(r, m, e, x, v);
		}
	}

	int query(int x, int v){
		return query(1, 0, n, x, v);
	}
};

struct suffix_array
{
	int n;
	vector<int> sa, lcp, rank;

	suffix_array(const string &s) : n(s.length() + 1), sa(n), lcp(n), rank(n)
	{
		vector<int> top(max(256, n));
		for (int i = 0; i < n; ++i)
			top[rank[i] = s[i] & 0xff]++;
		partial_sum(top.begin(), top.end(), top.begin());
		for (int i = 0; i < n; ++i)
			sa[--top[rank[i]]] = i;
		vector<int> tmp(n);
		for (int len = 1, j; len < n; len <<= 1)
		{
			for (int i = 0; i < n; ++i)
			{
				j = sa[i] - len;
				if (j < 0)
					j += n;
				tmp[top[rank[j]]++] = j;
			}
			sa[tmp[top[0] = 0]] = j = 0;
			for (int i = 1, j = 0; i < n; ++i)
			{
				if (rank[tmp[i]] != rank[tmp[i - 1]]
				    || rank[tmp[i] + len] != rank[tmp[i - 1] + len])
					top[++j] = i;
				sa[tmp[i]] = j;
			}
			copy(sa.begin(), sa.end(), rank.begin());
			copy(tmp.begin(), tmp.end(), sa.begin());
			if (j >= n - 1)
				break;
		}
		int i, j, k;
		for (j = rank[lcp[i = k = 0] = 0]; i < n - 1; ++i, ++k)
		{
			while (k >= 0 && s[i] != s[sa[j - 1] + k])
				lcp[j] = k--, j = rank[sa[j] + 1];
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	string s; cin >> s;
	unordered_map<int, vector<int>> um;

	vector<int> v(n + 2);
	for (int i = 0; i < n; ++i){
		v[i + 1] = v[i] + (s[i] == '(' ? 1 : -1);
		um[v[i + 1]].push_back(i + 1);
	}

	v[n + 1] = -0x3f3f3f3f;

	segment_tree st(v);
	suffix_array sa(s);

	int64 ans = 0;

	for (int i = 1; i <= n; ++i){
		int a = sa.sa[i] + 1;
		int b = a + sa.lcp[i];
		int c = st.query(a, v[a - 1]);

		if (c <= b) continue;

		vi &t = um[v[a - 1]];

		int cur = lower_bound(t.begin(), t.end(), c) - lower_bound(t.begin(), t.end(), b);

		ans += cur;
	}

	cout << ans << endl;

	return 0;
}