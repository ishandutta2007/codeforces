#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int Mod = 1e9 + 7;

const int maxn = 500;

struct data
{
	int cnt[65536];

	data() { memset(cnt, 0, sizeof cnt); }

	friend data operator+(const data &x, const data &y)
	{
		data ans;
		REP(i, 0, 65536) ans.cnt[i] = (x.cnt[i] + y.cnt[i]) % Mod;
		return ans;
	}

};

data I[256];

int n;
char s[maxn + 5];

data combine(const data &x, const data &y, const char &ty)
{
	data ans;
	vector<int> A, B;
	REP(i, 0, 65536)
		if (x.cnt[i]) A.pb(i);
	REP(i, 0, 65536)
		if (y.cnt[i]) B.pb(i);
	if ((LL)SZ(A) * SZ(B) <= 16 * 65536)
	{
		for (auto u : A)
			for (auto v : B)
				(ans.cnt[(ty == '|' ? (u | v) : (u & v))] += (LL)x.cnt[u] * y.cnt[v] % Mod) %= Mod;
	}
	static int a[65537], b[65537], c[65537];
	REP(i, 0, 65536) a[i] = x.cnt[i];
	REP(i, 0, 65536) b[i] = y.cnt[i];
	REP(i, 0, 16)
		REP(j, 0, 65536)
		{
			if ((j >> i & 1) ^ (ty == '|'))
			{
				(a[j ^ (1 << i)] += a[j]) %= Mod;
				(b[j ^ (1 << i)] += b[j]) %= Mod;
			}
		}
	REP(i, 0, 65536) c[i] = (LL)a[i] * b[i] % Mod;
	REP(i, 0, 16)
		REP(j, 0, 65536)
		{
			if ((j >> i & 1) ^ (ty == '|'))
			{
				(c[j ^ (1 << i)] -= c[j]) %= Mod;
			}
		}
	REP(i, 0, 65536) ans.cnt[i] = c[i];
	return ans;
}

inline data work(const int &l, const int &r)
{
	int now = 1;
	data ret;
	bool flag = 0;
	for (int i = l; i < r; ++i)
	{
		if (!now)
		{
			if (s[i] != '?' && s[i] != '&' && s[i] != '|') return data();
			flag = 1;
		}
		else
		{
			data lyc;
			int st = i;
			if (s[i] == '(')
			{
				if (!now) return data();
				int tmp = 0;
				while (i < r)
				{
					if (s[i] == '(') ++tmp;
					else if (s[i] == ')') --tmp;
					if (!tmp) break;
					++i;
				}
				lyc = work(st + 1, i);
			}
			else lyc = I[(int)s[i]];
			if (!flag) ret = lyc;
			else
			{
				if (s[st - 1] != '?') ret = combine(ret, lyc, s[st - 1]);
				else ret = combine(ret, lyc, '|') + combine(ret, lyc, '&');
			}
		}
		now = !now;
	}
	if (now) return data();
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", s);
	n = strlen(s);
	static int val[256] = {0};
	for (int i = 15; i >= 0; --i)	
	{
		REP(j, 0, 256) val[j] <<= 1;
		val['A'] |= (i & 1);
		val['a'] |= !(i & 1);
		val['B'] |= (i >> 1 & 1);
		val['b'] |= !(i >> 1 & 1);
		val['C'] |= (i >> 2 & 1);
		val['c'] |= !(i >> 2 & 1);
		val['D'] |= (i >> 3 & 1);
		val['d'] |= !(i >> 3  & 1);
	}
	I['A'].cnt[val['A']] = 1;
	I['a'].cnt[val['a']] = 1;
	I['B'].cnt[val['B']] = 1;
	I['b'].cnt[val['b']] = 1;
	I['C'].cnt[val['C']] = 1;
	I['c'].cnt[val['c']] = 1;
	I['D'].cnt[val['D']] = 1;
	I['d'].cnt[val['d']] = 1;
	I['?'] = I['A'] + I['a'] + I['B'] + I['b'] + I['C'] + I['c'] + I['D'] + I['d'];
	data tmp = work(0, n);
	int m;
	vector<pair<int, int> > all;
	scanf("%d", &m);
	REP(i, 0, m)
	{
		int a, b, c, d, e;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
		all.pb(mp(a | (b << 1) | (c << 2) | (d << 3), e));
	}
	int ret = 0;
	REP(i, 0, 65536)
	{
		bool flag = 1;
		for (auto it : all)
			if ((i >> it.x & 1) != it.y)
			{
				flag = 0;
				break;
			}
		if (flag) (ret += tmp.cnt[i]) %= Mod;
	}
	(ret += Mod) %= Mod;
	printf("%d\n", ret);
	return 0;
}