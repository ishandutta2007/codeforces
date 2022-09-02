#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, 1 : 0;}
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0;}

using namespace std;

typedef long long LL;

const int maxn = 5000000;

int n, m;
char s[maxn + 5];

int N;
int sa[maxn + 5], height[maxn + 5];

inline void init()
{
	scanf("%s%d", s, &m);
	n = strlen(s);
}

int nxt[maxn + 5];

char s0[maxn + 5], s1[maxn + 5], s2[maxn + 5], s3[maxn +5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	reverse(s, s + n);
	int u = 1, v = 0;
	int now = 0;
	nxt[0] = 0;
	nxt[1] = 0;
	sa[N++] = 0;
	REP(i, 1, n)
	{
		while (s[now + v] != s[i]) 
		{
			if (s[now + v] > s[i])
			{
				height[N - 1] = v;
				sa[N++] = i - v;
				now = i - v;
				u = v;
			}
			if (!v) break;
			v = nxt[v];
		}
		++u;
		if (u > 1 && s[now + v] == s[i]) ++v;
		nxt[u] = v;
	}
	while (v) height[N - 1] = v, sa[N++] = n - v, v = nxt[v];
	reverse(sa, sa + N);
	reverse(height, height + (N - 1)); 
	int lst = n;
	bool flag = 0;
	REP(i, 0, N)
	{
		int Min = height[i];
		int nxt = i + 1;
		bool tmp = sa[i] < lst - 1;
		if (!flag) tmp = 1;
		if (m - tmp < 2) break;
		if (tmp && Min >= lst - sa[i] && lst - sa[nxt] <= (lst - sa[i]) << 1) continue;
		REP(j, sa[i], lst) putchar(s[j]);
		flag = sa[i] == lst - 1;
		lst = sa[i];
		s[lst] = 0;
		m -= tmp;
	}
	if (m == 2)
	{
		memcpy(s1, s, sizeof s1);
		reverse(s1, s1 + lst);
		memcpy(s2, s1, sizeof s2);
		int Max = -1;
		REP(i, 1, lst)
		{
			if (Max == -1 || Max + nxt[Max] <= i) nxt[i] = 0;
			else nxt[i] = min(Max + nxt[Max] - i, nxt[i - Max]);
			while (i + nxt[i] < lst && s[i + nxt[i]] == s[nxt[i]]) ++nxt[i];
			if (Max == -1 || i + nxt[i] > Max + nxt[Max]) Max = i;
		}
		Max = -1;
		int max_reach = -1;
		int last_match = -1;
		int place = lst;
		REP(i, 0, lst)
		{
			if (i > place) break;
			int tmp = 0;
			if (Max == -1 || max_reach <= i) tmp = 0;
			else tmp = min(max_reach - i, nxt[i - Max]);
			char *now = last_match == -1 ? s1 + i + tmp : s + (i - last_match) + tmp;
			while (i + tmp < lst && *now == s[tmp]) ++tmp, ++now;
			if (*now > s[tmp])
			{
				chkmin(place, i + tmp);
				tmp = lst - i;
				last_match = i;
			}
			if (Max == -1 || i + tmp > max_reach) Max = i, max_reach = i + tmp;
		}
		if (last_match != -1) reverse(s1 + last_match, s1 + lst);
		int now = 0;
		REP(i, 0, N)
		{
			if (sa[i] >= lst) continue;
			int tmp = lst - sa[i];
			int flag = -1;
			REP(j, now, tmp) 
			{
				if (flag == -1 && s2[j] != s[sa[i] + j]) 
				{
					flag = s2[j] < s[sa[i] + j];
					break;
				}
			}
			if (flag == 1) break;
			flag = -1;
			int id = lst - 1;
			REP(j, now, tmp) 
			{
				if (flag == -1 && s2[id] != s[sa[i] + j]) 
				{
					flag = s2[id] < s[sa[i] + j];
					break;
				}
				--id;
			}
			if (flag == 1) break;
			REP(j, now, tmp) s2[j] = s[sa[i] + j];
			now = lst - sa[i];
			int Min = height[i];
			if (Min < lst - sa[i]) break;
		}
		memcpy(s3, s2, sizeof s3);
		reverse(s3 + now, s3 + lst);
		if (strcmp(s3, s2) < 0) memcpy(s2, s3, sizeof s2);
		if (strcmp(s1, s2) < 0) puts(s1);
		else puts(s2);
	}
	else
	{
		memcpy(s0, s, sizeof s0);
		reverse(s0, s0 + lst);
		if (strcmp(s0, s) < 0) puts(s0);
		else puts(s);
	}
	return 0;
}