#include <bits/stdc++.h>
using namespace std;
#define N 1000010
#define inf 1000000007

int tot, n, Q, ans, l, cnt;
int t[N][30], fail[N], id[N], col[N], q[N], c[N << 1], to[N << 1], next[N << 1],head[N], L[N], R[N];
char ch[N];

int lowbit(int x)
{
	return x & (-x);
}
void Insert(int x, int y)
{
	to[++ l] = y;
	next[l] = head[x];
	head[x] = l;
}
void add(int x,int val)
{
	int i = x;
	while(i <= cnt)
	{
		c[i] += val;
		i += lowbit(i);
	}
}
int get_sum(int x)
{
	int i = x, ret = 0;
	while(i)
	{
		ret += c[i];
		i -= lowbit(i);
	}
	return ret;
}
void Insert(int x)
{
	int now = 1;
	scanf("%s", ch);
	int Len = strlen(ch);
	for(int i = 0; i < Len; i ++)
	{
		int k = ch[i] - 'a' + 1;
		if(!t[now][k]) t[now][k] = ++ tot;
		now = t[now][k];
	}
	col[x] = 1;
	id[x] = now;
}

void dfs(int x)
{
	L[x] = ++ cnt;
	for(int i = head[x]; i; i = next[i]) dfs(to[i]);
	R[x] = ++ cnt;
}
int main()
{
	int k, p, x, Len;

	tot = 1;
	for(int i = 1; i <= 26; i ++) 
		t[0][i] = 1;
	scanf("%d %d", &Q, &n);
	for(int i = 1; i <= n; i ++) 
		Insert(i);

	q[0] = 1;
	fail[1] = 0;
	int top = 1, last = 0;
	while(top > last)
	{
		int k = q[last ++];
		for(int i = 1; i <= 26; i ++)
			if(t[k][i])
			{
				int p = fail[k];
				while(! t[p][i]) p = fail[p];
				fail[t[k][i]] = t[p][i];
				q[top ++] = t[k][i];
			}
	}

	for(int i = 1; i <= tot; i ++) 
		Insert(fail[i], i);
	dfs(0);
	for(int i = 1; i <= n; i ++)
		add(L[id[i]], 1),
		add(R[id[i]] + 1, -1);

	while(Q --)
	{
		scanf("%s",ch);
		Len = strlen(ch);
		if(ch[0] == '?')
		{
			int now = 1;
			ans = 0;
			for(int i = 1; i < Len; i ++)
			{
				int k = ch[i] - 'a' + 1;
				while(! t[now][k]) now = fail[now];
				now = t[now][k];
				ans += get_sum(L[now]);
			}
			printf("%d\n", ans);
		}
		else if(ch[0] == '-')
		{
			sscanf(ch + 1, "%d", &x);
			if(col[x])
			{
				col[x] = 0;
				add(L[id[x]], -1);
				add(R[id[x]] + 1, 1);
			}
		}
		else
		{
			sscanf(ch + 1, "%d", &x);
			if(!col[x])
			{
				col[x] = 1;
				add(L[id[x]], 1);
				add(R[id[x]] + 1, -1);
			}
		}
	}
	return 0;
}