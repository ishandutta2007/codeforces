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
#define LAST(x) ((x)[SZ(x) - 1])

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int oo = 0x3f3f3f3f;

const int maxn = 200000;

int n, m;

char s[maxn + 5];

vector<vector<int> > now;
int fir[maxn + 5], lst[maxn + 5];

set<int> L, R;
vector<int> LL, RR, LR, RL;

int nxt[maxn + 5], pre[maxn + 5];

inline void doit(const vector<int> &v)
{
	REP(i, 0, SZ(v) - 1) nxt[v[i]] = v[i + 1], pre[v[i + 1]] = v[i], assert(s[v[i]] != s[v[i + 1]]);
}

inline void print()
{
	REP(i, 0, n) if (pre[i] == -1)
	{
		int u = i;
		while (u != -1)
		{
			printf("%d ", u + 1);
			u = nxt[u];
		}
		break;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", s);
	n = strlen(s);
	int sum = 0, Min = 0, Max = 0;
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] == 'L') --sum;
		else ++sum;
		if (sum > Max || sum < Min)
		{
			chkmax(Max, sum);
			chkmin(Min, sum);
			if (s[i] == 'L') L.insert(SZ(now));
			else R.insert(SZ(now));
			now.pb(vector<int>(1, i));
		}
		else
		{
			int cur = 0;
			if (s[i] == 'L') cur = *R.begin();
			else cur = *L.begin();
			now[cur].pb(i);
			if (L.count(cur)) L.erase(cur), R.insert(cur);
			else R.erase(cur), L.insert(cur);
		}
	}
	memset(nxt, -1, sizeof nxt);
	memset(pre, -1, sizeof pre);
	printf("%d\n", Max - Min - 1);
	REP(i, 0, SZ(now))
	{
		bool tmp0 = s[now[i][0]] == 'L', tmp1 = s[LAST(now[i])] == 'L';
		if (tmp0 && tmp1) LL.pb(i);
		else if (tmp0) LR.pb(i);
		else if (tmp1) RL.pb(i);
		else RR.pb(i);
	}
	m = SZ(now);
	REP(i, 0, m)
	{
		doit(now[i]);
		fir[i] = now[i][0];
		lst[i] = LAST(now[i]);
	}
	REP(i, 1, SZ(LR))
	{
		int x = lst[LR[i - 1]];
		int y = fir[LR[i]];
		nxt[x] = y;
		pre[y] = x;
		assert(s[x] != s[y]);
		lst[LR[0]] = lst[LR[i]];
	}
	REP(i, 1, SZ(RL))
	{
		int x = lst[RL[i - 1]];
		int y = fir[RL[i]];
		nxt[x] = y;
		pre[y] = x;
		assert(s[x] != s[y]);
		lst[RL[0]] = lst[RL[i]];
	}
	if (SZ(RL) && SZ(LR))
	{
		int tmp0 = lst[LAST(LR)];
		int tmp1 = lst[LAST(RL)];
		int x = LR[0];
		int y = RL[0];
		LL.pb(x);
		RR.pb(y);
		LR.clear();
		RL.clear();
		if (tmp0 < tmp1) swap(tmp0, tmp1), swap(x, y);
		lst[x] = pre[tmp0];
		lst[y] = tmp0;
		assert(s[tmp0] != s[tmp1]);
		pre[tmp0] = tmp1;
		nxt[tmp1] = tmp0;
	}
	else
	{
		if (!SZ(LL) && !SZ(RR))
		{
			print();
			return 0;
		}
		else if (SZ(LR) || SZ(RL))
		{
			if ((SZ(LR) && SZ(LL)))
			{
				int x = lst[LR[0]], y = fir[LL[0]];
				assert(s[x] != s[y]);
				nxt[x] = y;
				pre[y] = x;
				lst[LR[0]] = lst[LL[0]];
				LL[0] = LR[0];
			}
			else if ((SZ(LL) && SZ(RL)))
			{
				int x = fir[RL[0]], y = lst[LL[0]];
				assert(s[x] != s[y]);
				nxt[y] = x;
				pre[x] = y;
				lst[LL[0]] = lst[RL[0]];
			}
			else if ((SZ(RL) && SZ(RR)))
			{
				int x = lst[RL[0]], y = fir[RR[0]];
				assert(s[x] != s[y]);
				nxt[x] = y;
				pre[y] = x;
				lst[RL[0]] = lst[RR[0]];
				RR[0] = RL[0];
			}
			else if ((SZ(RR) && SZ(LR)))
			{
				int x = fir[LR[0]], y = lst[RR[0]];
				assert(s[x] != s[y]);
				nxt[y] = x;
				pre[x] = y;
				lst[RR[0]] = lst[LR[0]];
			}
		}
	}
	int lyc = -1;
	bool cur = SZ(LL) > SZ(RR);
	while (SZ(LL) || SZ(RR))
	{
		int x = -1;
		if (cur) x = LAST(LL), LL.pop_back();
		else x = LAST(RR), RR.pop_back();
		assert(s[fir[x]] != s[lyc]);
		pre[fir[x]] = lyc;
		if (lyc >= 0) nxt[lyc] = fir[x];
		lyc = lst[x];
		cur = !cur;
	}
	print();
	return 0;
}