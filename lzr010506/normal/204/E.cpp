#include <bits/stdc++.h>
using namespace std;
inline int readint()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define CIR(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define ADJ(i, u) for (int i = hd[u]; i != -1; i = edge[i].nxt)
#define ECH(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define PII pair<int, int>
#define VI vector<int>
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define SZ(v) v.size()
#define ALL(v) v.begin(), v.end()
#define CLR(v, a) memset(v, a, sizeof(v))
#define IT iterator
#define LL long long
#define DB double
#define PI 3.1415926

const int N = 100005 << 1;

int Log[N];

void init()
{
	Log[0] = -1;
	for (int i = 1; i < N; i++)
		Log[i] = Log[i >> 1] + 1;
}

int arr[N];
char ss[N];
int m, K, pos[N], leng[N], pre[N];
int last[N], sor[N], val[N * 30], start[N << 2], tot, sum;

#define lch rt << 1, L, mid
#define rch rt << 1 | 1, mid + 1, R

void setup(int rt, int L, int R)
{
	int len = R - L + 1;
	start[rt] = tot;
	REP(i, L, R) val[tot++] = pre[i];
	sort(val + start[rt], val + start[rt] + len);
	if (L == R) return;
	int mid = L + R >> 1;
	setup(lch);
	setup(rch);
}

int query(int rt, int L, int R, int l, int r, int v)
{
	if (l <= L && R <= r)
	{
		int len = R - L + 1;
		int res = lower_bound(val + start[rt], val + start[rt] + len, v) - (val + start[rt]);
		return res;
	}

	int mid = L + R >> 1;
	int res = 0;

	if (l <= mid)
		res += query(lch, l, r, v);
	if (r > mid)
		res += query(rch, l, r, v);
	return res;
}

struct SA
{
	int s[N];
	int str[N];
	int sa[N], t[N], t2[N], c[N], n;
	int rank[N], h[N];
	vector<int> vec[N];

	struct ST
	{
		int d[N][17];
		int n;

		void init(int n, int *A)
		{
			this->n = n;
			for (int i = 1; i <= n; i++)
				d[i][0] = A[i];
			for (int j = 1; j <= Log[n]; j++)
				for (int i = 1; i + (1 << j) - 1 <= n; i++)
					d[i][j] = min(d[i][j - 1], d[i + (1 << j - 1)][j - 1]);
		}

		int query(int st, int ed)
		{
			int m = Log[ed - st + 1];
			return min(d[st][m], d[ed - (1 << m) + 1][m]);
		}

	}rmq;


	void init(int* str, int len)
	{
		FOR(i, len) s[i] = str[i];
		n = len;
		s[n] = 0;
	}

	void geth()
	{
		int i, j, k = 0;
		for (i = 0; i < n; i++) rank[sa[i]] = i;

		for (i = 0; i < n; i++)
		{
			if (k) k--;
			if (!rank[i]) continue;
			j = sa[rank[i] - 1];
			while (s[i + k] == s[j + k]) k++;
			h[rank[i]] = k;
		}

		rmq.init(n - 1, h);
	}

	void build(int m)
	{
		int i, *x = t, *y = t2;

		for (i = 0; i < m; i++) c[i] = 0;
		for (i = 0; i < n; i++) c[x[i] = s[i]]++;
		for (i = 1; i < m; i++) c[i] += c[i - 1];
		for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;

		for (int k = 1; k <= n; k <<= 1)
		{
			int p = 0;
			for (i = n - k; i < n; i++) y[p++] = i;
			for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;

			for (i = 0; i < m; i++) c[i] = 0;
			for (i = 0; i < n; i++) c[x[y[i]]]++;
			for (i = 1; i < m; i++) c[i] += c[i - 1];
			for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];

			swap(x, y);
			p = 1, x[sa[0]] = 0;

			for (i = 1; i < n; i++)
			{
				if (y[sa[i]] != y[sa[i - 1]])
					x[sa[i]] = p++;
				else if (sa[i] < n - k && sa[i - 1] < n - k)
					x[sa[i]] = y[sa[i] + k] == y[sa[i - 1] + k] ? p - 1 : p++;
				else
					x[sa[i]] = p++;
			}
			if (p >= n) break;
			m = p;
		}

		geth();
	}

	int lcp(int st, int ed)
	{
		if (st == ed) return n - st;
		int a = rank[st];
		int b = rank[ed];
		if (a > b)
			swap(a, b);
		return rmq.query(a + 1, b);
	}

	void run()
	{
		CLR(last, -1);

		FOR(i, sum)
		{
			int j = sa[i];
			pre[i] = last[sor[j]];
			last[sor[j]] = i;
		}

		setup(1, 0, sum - 1);

	}

	int solve(int p, int len)
	{
		int lt, rt, L, R;

		int r = rank[p];

		L = 0, R = r;

		while (L <= R)
		{
			int mid = L + R >> 1;
			if (lcp(sa[mid], p) >= len) R = mid - 1;
			else L = mid + 1;
		}

		lt = L;

		L = r, R = sum - 1;

		while (L <= R)
		{
			int mid = L + R >> 1;
			if (lcp(sa[mid], p) >= len)
				L = mid + 1;
			else
				R = mid - 1;
		}
		rt = R;
		if (p == 0 && len == 1);
		return query(1, 0, sum - 1, lt, rt, lt);
	}

	void gao(int id)
	{
		LL res = 0;

		int rt = pos[id];
		int ed = 0;

		FOR(i, leng[id])
		{
			int j = rt + i;

			if (ed < i) ed = i;

			while (ed < leng[id] && solve(j, ed - i + 1) >= K) ed ++;
			res += ed - i;
		}

		printf("%I64d ", res);
	}
}sol;

int main()
{
	init();
	scanf("%d%d", &m, &K);
	int rt = 0;
	int vv = 150;
	FOR(i, m)
	{
		scanf("%s", ss + rt);
		int len = strlen(ss + rt);
		sum += len;
		FOR(j, len)
		{
			arr[j + rt] = ss[j + rt];
			sor[j + rt] = i;
		}

		pos[i] = rt;
		leng[i] = len;

		arr[rt + len] = vv ++;
		sor[rt + len] = i + m;

		len++;
		rt += len;
	}


	sol.init(arr, rt);
	sol.build(vv);
	sol.run();

	FOR(i, m)
		sol.gao(i);
	puts("");
	return 0;
}