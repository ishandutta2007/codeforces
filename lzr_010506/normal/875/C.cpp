#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pii pair<int, int>
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 3e5 + 10;
int n, m, now, pre;
int len[N];
vector<int> a[N];
bool flag[N];
int cnt, to[N << 2],Next[N << 2],head[N];
int ans[N], edge[N];
queue<int> q;
bool last = 0;

void ins(int u, int v)
{
	to[++ cnt] = v;
	Next[cnt] = head[u];
	head[u] = cnt;
}


int main()
{
	n = read();
	m = read();
	rep(i, 1, n)
	{
		len[i] = read();
		rep(j, 1, len[i]) a[i].pb(read());
	}
	rrep(j, n - 1, 1)
	{
		bool flag = 0;
		rep(i, 0, min(len[j + 1], len[j]) - 1)
		{
			if (a[j + 1][i] != a[j][i]) ins(a[j + 1][i],a[j][i]),edge[a[j][i]] ++, flag = 1;
			if (a[j + 1][i] != a[j][i]) break;
		}	
		if (len[j] > len[j + 1] && !flag)
		{
			puts("No");
			return 0;
		}
	}
	int sum = m;
	rep(i, 1, m) 
		if (!edge[i])
		{
			sum --;
			q.push(i);
		}
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int e = head[u]; e; e = Next[e])
		{
			int v = to[e];
			edge[v] --;
			if (v > u)
			{
				if (flag[u])
				{
					puts("No");
					return 0;
				}
				else flag[v] = 1;
			}
			else flag[v] = flag[u];
			if (!edge[v])
			{
				sum --;
				q.push(v);
			}
		}
	}
	if (sum)
	{
		puts("No");
		return 0;
	}
	int ans1 = 0;
	rep(i, 1, m)
		if(flag[i])
			ans[++ ans1] = i;

	puts("Yes");
	printf("%d\n", ans1);
	rep(i, 1, ans1) printf("%d ",ans[i]);
	puts("");
	return 0;
}