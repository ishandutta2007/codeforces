#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp Maxke_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define mod 1000000007
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

const int N = 1100010;
struct Node
{
	int len, link;
	map<char, int> nxt;
	bool flag;
	int id;
} tmp[N * 2];
 
Node st[N * 2];
int sz, last;
void extend(char c,int id)
{
	int cur = sz ++;
	st[cur].len = st[last].len + 1;
	st[cur].flag = false;
	st[cur].id = (1 << id);
	int p;
	for(p = last; ~p && !st[p].nxt.count(c); p = st[p].link) st[p].nxt[c] = cur;
	if(p == -1) st[cur].link = 0;
	else
	{
		int q = st[p].nxt[c];
		if(st[p].len + 1 == st[q].len) st[cur].link = q;
		else
		{
			int now = sz ++;
			st[now].len = st[p].len + 1;
			st[now].nxt = st[q].nxt;
			st[now].link = st[q].link;
			st[now].flag =true;
			for (;~p && st[p].nxt[c] == q; p = st[p].link) st[p].nxt[c] = now;
			st[q].link = st[cur].link = now;
		}
	}
	last = cur;
}

char s[50005];
char pt[50005];
int dp2[N], dp[N], mark[N], idx[N * 2], Deg[N * 2];
pii Q[10];
char T[10][50005];
int len[15];
int main()
{
	scanf("%s",s);
	int n = strlen(s);
	rep(i, 0, N * 2 - 1) st[i].nxt.clear();
	sz = last = 0;
	st[0].len = 0;
	st[0].link = -1;
	sz ++;
	int q;
	cin >> q;
	rep(i, 0, n - 1) extend(s[i] - 'a', q);
	extend(26, q + 1);
	rep(i, 0, q - 1)
	{
		int l, r;
		scanf("%s%d%d", T[i], &l, &r);
		Q[i] = {l, r};
		len[i] = strlen(T[i]);
		rep(j, 0, len[i]) extend(T[i][j] - 'a', i);
		extend(26, q + 1);
	}
	int m = 0;
	rep(i, 0, sz - 1) 
		for(auto nw : st[i].nxt) 
			Deg[nw.Y] ++;

	tmp[m ++] = st[0];
	idx[0] = 0;
	rep(i, 0, sz - 1)
	{
		for(auto nw : tmp[i].nxt) 
			if(-- Deg[nw.Y] == 0)
			{
				idx[nw.Y] = m;
				tmp[m ++] = st[nw.Y];
			}
	}
	rep(i, 0, sz - 1)
	{
		for(auto& nw:tmp[i].nxt) 
			if(~nw.Y)
				nw.Y = idx[nw.Y];
		tmp[i].link = idx[tmp[i].link];
	}
	rep(i, 0, sz - 1) st[i] = tmp[i];
	ll ans = 0;
	dp[0]=1;
	rep(i, 0, sz - 1)
		for(auto e : st[i].nxt)
			dp[e.Y] += dp[i];

	rep(j, 0, q)
	{
	    memset(dp2, 0, sizeof(dp2));
		rrep(i, sz - 1, 0)
		{
			if(!st[i].flag && st[i].id >> j & 1) dp2[i] ++;
			if(i) dp2[st[i].link] += dp2[i];
		}
		if(j < q)
		{
			rep(i, 0, sz - 1) 
				if(dp2[i] >= Q[j].X && dp2[i] <= Q[j].Y)
					mark[i] ++;
		}
		else
			rep(i, 0, sz - 1) 
				if(dp2[i] > 0 && mark[i] == q && i) 
				    ans += dp[i];	
	}
	cout << ans << endl;
	return 0;
}