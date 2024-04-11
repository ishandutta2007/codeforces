#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pi complex<ld>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
#define EPS 1e-8
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
#define M 12
#define S 15
#define T 200
#define L 500005
#define N 16
#define inf 0x3f3f3f3f
struct node
{
	int flag;
	int next[27];
}tree[T];
int size, n, i, j, k, m, len, top, tmp, Min, ans, idx, x;
int hash[M][L], dp[1 << N][N * N] ,zy[N][1 << N], next[L][N], pos[N];
char s[S];

void insert(int rt,int k,int flag)
{
	if(k > len)
	{
		tree[rt].flag = flag;
		return;
	}
	if(tree[rt].next[s[k] - 'a'] == 0)
	{
		top ++;
		tree[rt].next[s[k] - 'a'] = top;
	}
	insert(tree[rt].next[s[k] - 'a'], k + 1, flag);
	return ;
}

int find(int rt,int k)
{
	if(k > len) return tree[rt].flag;
	if(tree[rt].next[s[k] - 'a'] == 0) return 0;
	return find(tree[rt].next[s[k] - 'a'], k + 1);
}

void Dp(int k)
{
	rep(i, 1, n) pos[i] = next[hash[k][0] + 1][i] = hash[k][0] + 1;
	rrep(i, hash[k][0], 1)
	{
		pos[hash[k][i]] = i;
		rep(j, 1, n)
			next[i][j] = pos[j];
	}
	memset(dp, inf, sizeof(dp));
	dp[0][0] = 0;
	rep(i, 0, (1 << n) - 1)
		rep(j, 0, size)
			if(dp[i][j] <= hash[k][0])
				rep(p, 1, n)
					if(!(i & (1 << (p - 1))))
	   					dp[i | (1 << (p - 1))][j + zy[p][i]] = min(dp[i | (1 << (p - 1))][j + zy[p][i]], next[dp[i][j] + 1][p]);
				   	
	rep(i, 0, size)
		if(dp[(1 << n) - 1][i] <= hash[k][0])
		{
			ans = i;
			return;
		}
	return ;
}

bool judge(int k)
{
	int used[N];
	rep(i, 1, n) used[i] = 0;
	rep(i, 1, hash[k][0]) used[hash[k][i]] = 1;
	rep(i, 1, n)
		if(!used[i])
			return false;
	return true;
}

int main()
{
	n = read();
	size = (n * (n - 1)) / 2;
	rep(i, 1, n)
	{
		scanf("%s", s + 1);
		len = strlen(s + 1);
		insert(0, 1, i);
	}
	m = read();
	rep(i, 1, m)
	{
		k = read();
		rep(j, 1, k)
		{
			scanf("%s", s + 1);
			len = strlen(s + 1);
			tmp = find(0, 1);
			if(tmp)
			{
				hash[i][0] ++;
				hash[i][hash[i][0]] = tmp;
			}
		}
	}
	rep(i, 1, n)
		rep(j, 0, (1 << n) - 1)
		{
			x = 0;
			rep(k, i + 1, n)
				if(j & (1 << (k - 1)))
					x ++;
			zy[i][j] = x;
		}
	Min = inf;
	idx = 0;
	rep(i, 1, m)
		if(judge(i))
		{
			ans = inf;
			Dp(i);
			if(ans < Min)
			{
				Min = ans;
				idx = i;
			}
		}
	if(idx)
	{
		printf("%d\n",idx);
		printf("[:");
		tmp = ((n * (n - 1)) / 2) - Min + 1;
		rep(i, 1, tmp) printf("|");
		printf(":]\n");
	}
	else printf("Brand new problem!\n");
	return 0;
}