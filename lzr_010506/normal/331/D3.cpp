#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).sze()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
#define N 100010
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
ll dx[4]={0, 0, -1, 1};
ll dy[4]={1, -1, 0, 0};
int n,m,q;
char s[11];
ll bz[N << 1][52];
int pos[N << 1][52];
int head[N << 1], nex[N << 1], val[N << 1], op[N << 1], tot;
int T[N << 2];
void pushdown(int rt)
{
	if(T[rt])
	{
		T[ls] = T[rs] = T[rt];
		T[rt] = 0;
	}
}
void insert(int l, int r, int rt, int x, int y ,int v)
{
	if(x <= l && r <= y) {T[rt] = v;return;}
	int mid = l + r >> 1;
	pushdown(rt);
	if(mid >= x) insert(l, mid, ls, x, y, v);
	if(mid < y) insert(mid + 1, r, rs, x, y, v);
}
int query(int l,int r,int rt,int v)
{
	if(l == r)return T[rt];
	int mid = l + r >> 1;
	pushdown(rt);
	if(mid >= v)return query(l, mid, ls, v);
	else return query(mid + 1, r, rs, v);
}
void add(ll x, ll y, int tp)
{
	tot ++;
	nex[tot] = head[x];
	head[x] = tot;
	val[tot] = y;
	op[tot] = tp;
}
struct vec
{
	ll x1,x2,y1,y2;
	int op;
	void read()
	{
		scanf("%I64d%I64d%I64d%I64d", &x1, &y1, &x2, &y2);
		if(y1 < y2) op = 0;
		if(y1 > y2) op = 1;
		if(x1 > x2) op = 2;
		if(x1 < x2) op = 3;
	}
}a[N];
struct node
{
	int op;
	ll len,x,y;
	void read()
	{
		scanf("%I64d%I64d%s%I64d", &x, &y, s, &len);
		if(s[0] == 'U') op = 0;
		if(s[0] == 'D') op = 1;
		if(s[0] == 'L') op = 2;
		if(s[0] == 'R') op = 3;
	}
}b[N];
pii cal(ll x,ll y,int p)
{
	if(a[p].x1 == a[p].x2)
	{
		if(a[p].x1 == x)
		{
			if(min(a[p].y1, a[p].y2) <= y && y <= max(a[p].y1, a[p].y2)) return mp(x,y);
			if(y < min(a[p].y1, a[p].y2)) return mp(x,min(a[p].y1, a[p].y2));
			else return mp(x, max(a[p].y1,a[p].y2));
		}
		else return mp(a[p].x1, y);
	}
	else
	{
		if(a[p].y1 == y)
		{
			if(min(a[p].x1, a[p].x2) <= x && x <= max(a[p].x1, a[p].x2)) return mp(x, y);
			if(x < min(a[p].x1, a[p].x2)) return mp(min(a[p].x1, a[p].x2), y);
			else return mp(max(a[p].x1, a[p].x2), y);
		}
		else return mp(x,a[p].y1);
	}
}
int dis(ll x1, ll y1, ll x2, ll y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}
pii find(ll x, ll y, int tp, ll step)
{
	return mp(x + step * dx[tp], y + step * dy[tp]);
}
void print(pii p)
{
	ll x = p.X, y = p.Y;
	x = max(x, 0ll); x = min(x, (ll)m);
	y = max(y, 0ll); y = min(y, (ll)m);
	printf("%I64d %I64d\n", x, y);
}

int main()
{
	n = read();
	m = read();
	rep(i, 1, n) a[i].read();
	q = read();
	rep(i, 1, q) b[i].read();
	rep(i, 0, 3)
	{
		tot = 0;
		memset(head, 0, sizeof(head));
		memset(T, 0, sizeof(T));
		rep(j, 1, q)
			if(b[j].op == i)
			{
				if(i < 2) add(b[j].y, j + n, 1);
				else add(b[j].x, j + n, 1);
			}
		rep(j, 1, n)
		{
			if(i == 0) add(max(a[j].y1, a[j].y2), j, 0);
			if(i == 1) add(min(a[j].y1, a[j].y2), j, 0);
			if(i == 2) add(min(a[j].x1, a[j].x2), j, 0);
			if(i == 3) add(max(a[j].x1, a[j].x2), j, 0);
		}
		rep(j, 1, n)
			if(a[j].op == i)
			{
				if(i < 2) add(a[j].y2, j, 1);
				else add(a[j].x2, j, 1);
			}
		int now = (i == 0 || i == 3) ? m:0;
		while(now != -1 && now != m + 1)
		{
			for(int j = head[now]; j; j = nex[j])
			{
				if(!op[j])
				{
					if(i < 2) insert(0, m, 1, min(a[val[j]].x1, a[val[j]].x2), max(a[val[j]].x1, a[val[j]].x2), val[j]);
					else insert(0, m, 1, min(a[val[j]].y1, a[val[j]].y2), max(a[val[j]].y1,a[val[j]].y2),val[j]);
				}
				else
				{
					int tmp;
					if(val[j] <= n)
					{
						if(i < 2) tmp = query(0, m, 1, a[val[j]].x1);
						else tmp = query(0, m, 1, a[val[j]].y1);
					}
					else
					{
						if(i < 2) tmp = query(0, m, 1, b[val[j] - n].x);
						else  tmp = query(0, m, 1, b[val[j] - n].y);
					}
					pos[val[j]][0] = tmp;
					if(tmp)
					{
						if(val[j] <= n)bz[val[j]][0] = abs(a[tmp].x2 - a[val[j]].x2) + abs(a[tmp].y2 - a[val[j]].y2);
						else bz[val[j]][0] = abs(a[tmp].x2 - b[val[j] - n].x) + abs(a[tmp].y2 - b[val[j] - n].y);
					}
					else bz[val[j]][0] = 1ll << 50;
				}
			}
			if(i == 0 || i == 3) now --;
			else now ++;
		}
	}
	rep(i, 1, 50) bz[0][i] = 1ll << 50;
	rep(i, 1, 50)
		rep(j, 1, n + q)
		{
			pos[j][i] = pos[pos[j][i - 1]][i - 1];
			bz[j][i] = bz[j][i - 1] + bz[pos[j][i - 1]][i - 1];
			bz[j][i] = min(bz[j][i], 1ll << 50);
		}
	rep(i, 1, q)
	{
		int tmp = i + n;
		ll t = b[i].len;
		rrep(j, 50, 0)
			if(bz[tmp][j] <= t)
			{
				t -= bz[tmp][j];
				tmp = pos[tmp][j];
			}
		if(tmp == i + n)
		{
			if(pos[tmp][0])
			{
				pii tq = cal(b[i].x, b[i].y, pos[tmp][0]);
				int tw = dis(tq.X, tq.Y, b[i].x, b[i].y);
				if(tw >= t) print(find(b[i].x, b[i].y, b[i].op, t));
				else print(find(tq.X, tq.Y, a[pos[tmp][0]].op, t - tw));
			}
			else print(find(b[i].x, b[i].y, b[i].op, t));
		}
		else
		{
			if(!pos[tmp][0]) print(find(a[tmp].x2, a[tmp].y2, a[tmp].op, t));
			else
			{
				pii tq = cal(a[tmp].x2, a[tmp].y2, pos[tmp][0]);
				int tw = dis(tq.X, tq.Y, a[tmp].x2, a[tmp].y2);
				if(tw >= t) print(find(a[tmp].x2, a[tmp].y2, a[tmp].op, t));
				else print(find(tq.X, tq.Y, a[pos[tmp][0]].op, t - tw));
			}
		}
	}
	return 0;
}