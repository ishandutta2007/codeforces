#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int Mod = 1e9 + 7;

const int maxn = 1000100;

int n;
char s[maxn + 5];

int dp[maxn + 5];

struct seg 
{
	int a, k, sz;

	seg(int _a, int _k, int _sz): a(_a), k(_k), sz(_sz) { } 

};

vector<seg> G;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	static char ss[maxn + 5];
	scanf("%s", ss);
	n = strlen(ss);
	if (n & 1)
	{
		printf("0\n");
		return 0;
	}
	REP(i, 0, n >> 1)
	{
		s[i << 1] = ss[i];
		s[i << 1 | 1] = ss[n - i - 1];
	}

	static int pd[maxn + 5];
	dp[0] = 1;
	REP(i, 0, n)
	{
		vector<seg> G1, G2;	
		for (auto p:G) 
		{
			if (p.a > 0 && s[p.a - 1] == s[i]) G1.pb(seg(p.a - 1, p.k, p.sz));
		}
		int lst = -i;
		for (auto p : G1) 
		{
			if (p.a - lst != p.k) 
			{
				G2.pb(seg(p.a, p.a - lst, 1));
				if (p.sz > 1) G2.pb(seg(p.a + p.k, p.k, p.sz - 1));
			} 
			else G2.pb(p);
			lst = p.a + (p.sz - 1) * p.k;
		}
		if (i > 0 && s[i - 1] == s[i]) G2.pb(seg(i - 1, i - 1 - lst , 1)), lst = i - 1;
//		G2.pb(seg(i, i - lst, 1));
		G.clear();
		if (!G2.empty())
		{
			seg cur = G2[0]; 
			G2.erase(G2.begin());
			for (auto p : G2) 
			{
				if (p.k == cur.k) cur.sz += p.sz;
				else G.pb(cur), cur = p;
			}
			G.pb(cur);
		}
		dp[i + 1] = 0;
		for (auto p : G) 
		{
			int tmp = p.a + (p.sz - 1) * p.k;
			int cnt = dp[tmp];
			if (p.sz > 1) (cnt += pd[p.a - p.k]) %= Mod;
			if (p.k <= p.a) pd[p.a - p.k] = cnt;
			(dp[i + 1] += cnt) %= Mod;
		}
	}
	int ans = dp[n];
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}