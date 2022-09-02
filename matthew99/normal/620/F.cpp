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

const int __buffsize = 100000;
char __buff[__buffsize];
char *__buffs, *__buffe;

#define getc() (__buffs == __buffe ? fread(__buff, 1, __buffsize, stdin), __buffe = __buff + __buffsize, *((__buffs = __buff)++): *(__buffs++))

template<typename T> inline T &Read(T &x)
{
	static char c;
	while (1) 
	{ 
		c = getc(); 
		if (c == '-' || (c >= '0' && c <= '9')) break; 
	}
	bool flag = c == '-';
	x = flag ? 0 : c - '0';
	while (1)
	{
		c = getc();
		if (c < '0' || c > '9') break;
		(x *= 10) += c - '0';
	}
	if (flag) x = -x;
	return x;
}

#undef getc

const int maxabs = 1048576, max0 = 20;

const int maxn = 50000, maxm = 5000;

const int block_sz = 500, block_cnt = 100;

int sum[maxabs + 5];

int n, m;
int a[maxn + 5];

int Max[max0][maxabs];
int Min[max0][maxabs];

vector<int> all_add;

inline void trie_init()
{
	for (auto x : all_add)
	{
		REP(i, 0, max0) Min[i][sum[a[x]] & ((1 << max0) - (1 << i))] = oo;
		REP(i, 0, max0) Max[i][sum[a[x] + 1] & ((1 << max0) - (1 << i))] = -oo;
	}
	all_add.clear();
}

inline void trie_add(int x)
{
	all_add.pb(x);
	REP(i, 0, max0) chkmin(Min[i][sum[a[x]] & ((1 << max0) - (1 << i))], a[x]);
	REP(i, 0, max0) chkmax(Max[i][sum[a[x] + 1] & ((1 << max0) - (1 << i))], a[x]);
}

inline int trie_query(int x)
{
	int best = (~sum[a[x] + 1]) & ((1 << max0) - 1);
	int ret = 0;
	for (int i = max0 - 1; i >= 0; --i) if (Min[i][best & ((1 << max0) - (1 << i))] > a[x]) best ^= 1 << i;
	chkmax(ret, sum[a[x] + 1] ^ best);
	best = (~sum[a[x]]) & ((1 << max0) - 1);
	for (int i = max0 - 1; i >= 0; --i) 
	{
		if (Max[i][best & ((1 << max0) - (1 << i))] <= a[x]) best ^= 1 << i;
	}
	chkmax(ret, sum[a[x]] ^ best);
	return ret;
}

int l[maxm + 5], r[maxm + 5];
int ans[maxm + 5];

vector<int> all[block_cnt + 5];

inline bool cmp(int x, int y) { return r[x] < r[y]; }

inline int calc(int l, int r) { int ret = 0; trie_init(); REP(i, l, r) { trie_add(i), chkmax(ret, trie_query(i)); } return ret; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(Max, -oo, sizeof Max);
	memset(Min, oo, sizeof Min);
	all_add.clear();
	sum[0] = 0;
	REP(i, 0, maxabs) sum[i + 1] = sum[i] ^ i;
	Read(n), Read(m);
	REP(i, 0, n) Read(a[i]);
	memset(ans, 0, sizeof ans);
	int tot = (n - 1) / block_sz + 1;
	REP(i, 0, m)
	{
		Read(l[i]), Read(r[i]), --l[i];
		if (r[i] - l[i] <= block_sz) ans[i] = calc(l[i], r[i]);
		else 
		{
			int tmp = l[i] / block_sz;
			ans[i] = calc(l[i], (tmp + 1) * block_sz), all[tmp].pb(i);
		}
	}
	REP(i, 0, tot)
	{
		trie_init();
		int st = (i + 1) * block_sz;
		int now = st;
		int ret = 0;
		sort(ALL(all[i]), cmp);
		for (auto x : all[i]) 
		{
			while (now != r[x]) 
			{
				trie_add(now);
				chkmax(ret, trie_query(now));
				++now;
			}
			chkmax(ans[x], ret);
			REP(i, l[x], st) chkmax(ans[x], trie_query(i));
		}
	}
	REP(i, 0, m) printf("%d\n", ans[i]);
	return 0;
}