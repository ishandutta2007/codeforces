#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1e18;

struct TNode
{
    int u;
    long long val;
} cur, tmp;
vector<TNode> adj[400005];
vector<int> ls, rs;
int i, n, q, s, l1, r1, l2, r2, t, w;
long long tree[400005];
bool chk[400005], fin[400005];

inline bool operator<(const TNode &a, const TNode &b)
{
    return a.val > b.val || (a.val == b.val && a.u > b.u);
}
priority_queue<TNode, vector<TNode>, less<TNode>> pq;

void init(int l, int r, int i)
{
    if (l == s && r == s)
    {
        tree[i] = 0;
        pq.push((TNode){i, 0});
    }
    else
        tree[i] = INF;
    if (l == r)
	{
		fin[i] = true;
        return;
	}
    init(l, (l + r) >> 1, i << 1);
    init(((l + r) >> 1) + 1, r, (i << 1) + 1);
}

void add(int l, int r, int i, int L, int R, vector<int> &x)
{
    if (l > R || r < L)
        return;
    if (L <= l && r <= R)
    {
        x.push_back(i);
        return;
    }
    add(l, (l + r) >> 1, i << 1, L, R, x);
    add(((l + r) >> 1) + 1, r, (i << 1) + 1, L, R, x);
}

void upd(int i)
{
	if (fin[i])
		return;
	if (tree[i << 1] > tree[i])
	{
		tree[i << 1] = tree[i];
		pq.push((TNode){i << 1, tree[i]});
		upd(i << 1);
	}
	if (tree[(i << 1) + 1] > tree[i])
	{
		tree[(i << 1) + 1] = tree[i];
		pq.push((TNode){(i << 1) + 1, tree[i]});
		upd((i << 1) + 1);
	}
}

long long que(int l, int r, int i, int u)
{
    if (l == r)
        return tree[i] == INF ? -1 : tree[i];
    int m = (l + r) >> 1;
    return u <= m ? que(l, m, i << 1, u) : que(m + 1, r, (i << 1) + 1, u);
}

void Dijkstra()
{
    while (!pq.empty())
    {
        for (cur = pq.top(), pq.pop(), upd(cur.u); cur.u > 0 && (!chk[cur.u]); cur.u >>= 1)
		{
			chk[cur.u] = true;
            for (TNode v : adj[cur.u])
                if (tree[v.u] > cur.val + v.val)
                {
                    tree[v.u] = cur.val + v.val;
                    pq.push((TNode){v.u, tree[v.u]});
                }
		}
        while (!pq.empty() && tree[pq.top().u] > pq.top().val)
            pq.pop();
    }
}

int main()
{
    scanf("%d%d%d", &n, &q, &s);
    init(1, n, 1);
    while (q--)
    {
        scanf("%d", &t);
        if (t == 1)
        {
            scanf("%d%d%d", &l1, &l2, &w);
            r1 = l1;
            r2 = l2;
        }
        else if (t == 2)
        {
            scanf("%d%d%d%d", &l1, &l2, &r2, &w);
            r1 = l1;
        }
        else
        {
            scanf("%d%d%d%d", &l2, &l1, &r1, &w);
            r2 = l2;
        }
        add(1, n, 1, l1, r1, ls);
        add(1, n, 1, l2, r2, rs);
        for (int i : ls)
            for (int j : rs)
                adj[i].push_back((TNode){j, w});
        ls.clear();
        rs.clear();
    }
    Dijkstra();
    for (i = 1; i <= n; i++)
        printf("%I64d ", que(1, n, 1, i));
}