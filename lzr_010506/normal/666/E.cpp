#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
using namespace std;
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
const int N = 5e5 + 10;
const int M = 1300010;
int n, m, Q, pos[N];
char S[N], s[N];
int root = 1, sz = 1, last = 1, par[M], son[M][27], len[M], st[M], id[M];
void Extend(int c)
{
    int cur = ++ sz, p = last;
    len[cur] = len[p] + 1;
    while (p && !son[p][c]) son[p][c] = cur, p = par[p];
    if (!p) par[cur] = root;
    else
    {
        int q = son[p][c];
        if (len[p] + 1 == len[q]) par[cur] = q;
        else
        {
            int nq = ++ sz;
            memcpy(son[nq], son[q], sizeof(son[nq]));
            len[nq] = len[p] + 1;
            par[nq] = par[q];
            while (p && son[p][c] == q)
            	son[p][c] = nq, p = par[p];
            par[q] = par[cur] = nq;
        }
    }
    last = cur;
}

struct SgtNode
{
    pii key;
    int lson, rson;
}t[M * 23];

pii operator * (const pii & A,const pii &B)
{
	return A.X == B.X ? (A.Y < B.Y ? A : B) : (A.X > B.X ? A : B);
}

pii operator + (const pii & A,const pii &B)
{
	return mp(A.X + B.X, A.Y);
}

int cnt, roots[M], fa[21][M];
void Insert(int &x,int val,int l,int r)
{
    if(!x) x = ++ cnt;
    if (l == r)
    {
    	t[x].key.X ++;
    	t[x].key.Y = l;
    	return;
    }
    int mid = (l + r) >> 1;
    if (val <= mid) Insert(t[x].lson, val, l, mid);
    else Insert(t[x].rson, val, mid + 1, r);
    t[x].key = t[t[x].lson].key * t[t[x].rson].key;
}

int Merge(int x,int y,int l,int r)
{
    if (!x || !y) return x | y;
    int z = ++ cnt;
    if (l == r)
    {
        t[z].key = t[x].key + t[y].key;
        return z;
    }
    int mid = (l + r) >> 1;
    t[z].lson = Merge(t[x].lson, t[y].lson, l, mid);
    t[z].rson = Merge(t[x].rson, t[y].rson, mid + 1, r);
    t[z].key = t[t[z].lson].key * t[t[z].rson].key;
    return z;
}

pii Query(int x,int l,int r,int L,int R)
{
    if (!x) return mp(0,0);
    if (L <= l && R >= r) return t[x].key;
    int mid = (l + r) >> 1;
    if (R <= mid) return Query(t[x].lson, l, mid, L, R);
    else if (L > mid) return Query(t[x].rson, mid + 1, r, L, R);
    else return Query(t[x].lson, l, mid, L, mid) * Query(t[x].rson, mid + 1, r, mid + 1, R);
}
int Get(int l, int r)
{
    int Len = r - l + 1, x = pos[r];
    rrep(i, 20, 0)
    	if(len[fa[i][x]] >= Len)
    		x = fa[i][x];
    return x;
}

int main()
{
	scanf("%s", S + 1);
	int n = strlen(S + 1);
	rep(i, 1, n)
	{
		Extend(S[i] - 'a');
		pos[i] = last;
	}
	Extend(26);
	m = read();
	rep(i, 1, m)
	{
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		rep(j, 1, len)
		{
			Extend(s[j] - 'a');
			Insert(roots[last], i, 1, m);
		}
		Extend(26);
	}
	rep(i, 0, sz) st[i] = 0;
	rep(i, 1, sz) st[len[i]] ++;
	rep(i, 0, sz) st[i] += st[i - 1];
	rep(i, 1, sz) id[st[len[i]] --] = i;
	rrep(i, sz, 1)
	{
		int x = id[i];
		if(par[x]) roots[par[x]] = Merge(roots[par[x]], roots[x], 1, m);
	}
	rep(i, 1, sz) fa[0][i] = par[i];
	rep(j, 1, 20)
		rep(i, 1, sz)
			fa[j][i] = fa[j - 1][fa[j - 1][i]];
    Q = read();
    while (Q --)
    {
        int l = read(), r = read(), pl = read(), pr = read();
        int x = Get(pl, pr);
        pii ans = Query(roots[x], 1, m, l, r);
        if (!ans.X) printf("%d %d\n", l, 0);
        else printf("%d %d\n", ans.Y, ans.X);
    }
	return 0;
}