#include <bits/stdc++.h>
using namespace std;
#define N 300010
#define inf 1e10
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
struct node
{
    double x, y, lz, k, lk, lb;
    node *ch[2], *pre;
    node(double _x, double _y, double _k):x(_x),y(_y),k(_k)
    {
    	lk = lb = lz = 0;
    	pre = ch[0] = ch[1] = NULL;
    }
    inline void update()
    {
        if (lk || lb)
        {
            k += lk;
            y += lk * x + lb;
            if (ch[0]) ch[0] -> lk += lk, ch[0] -> lb += lb + ch[0] -> lz * lk;
            if (ch[1]) ch[1] -> lk += lk, ch[1] -> lb += lb + ch[1] -> lz * lk;
            lk = lb = 0;
        }
        if (lz)
        {
            x += lz;
            if (ch[0]) ch[0] -> lz += lz;
            if (ch[1]) ch[1] -> lz += lz;
            lz = 0;
        }
    }
    inline int d()
    {
        return pre -> ch[1] == this;
    }
};
inline void rotate(node *u)
{
    node *v = u -> pre;
    if (v -> pre) v -> pre -> update();
    v -> update();
    u -> update();
    if (v -> pre) v -> pre -> ch[v -> d()] = u;
    int d = u -> d();
    u -> pre = v -> pre;
    v -> pre = u;
    if (u -> ch[d ^ 1]) u -> ch[d ^ 1] -> pre = v;
    v -> ch[d] = u -> ch[d ^ 1];
    u -> ch[d ^ 1] = v;
}

inline void spaly(node *u)
{
    u -> update();
    while (u -> pre) rotate(u);
}

node* search(node *u)
{
    if (!u) return 0;
    u -> update();
    if (u -> y > 0)
    {
        node *ans = search(u -> ch[0]);
        return ans ? ans : u;
    }
    return search(u -> ch[1]);
}

int cut(node *r,node* &l)
{
    spaly(r);
    l = r -> ch[0];
    r -> ch[0] = 0;
    if (l) l -> pre  = 0;
}

node* rest(node *l)
{
    if (!l) return 0;
    while (l -> ch[1]) l -> update(), l = l -> ch[1];
    l -> update();
    return l;
}

node* link(node *l,node *r)
{
    if (l == 0) return r;
    if (r == 0) return l;
    l = rest(l);
    spaly(l);
    l -> ch[1] = r;
    r -> pre = l;
    return l;
}

double c[N],ans[N],w[N];
int main()
{
    int n, q, a, b;
    n = read();
    q = read();
    a = read();
    b = read();
    for (int i = 1; i <= n; i ++)
        c[i] = read();
    node *root = new node(q, q * 2 - 2 * c[1], 2);
    for (int i = 2; i <= n; i ++)
    {
        node *r = search(root), *l;
        cut(r, l);
        w[i] = r -> x - r -> y / r -> k;
        if (l) w[i] = max(rest(l) -> x, w[i]);
        if (w[i] >= (i - 2) * a + 1)
        {
            l = link(l,new node(w[i], 0, r -> k));
            r = link(new node(w[i], 0, 0), r);
            l -> lz += a;
            r -> lz += b;
            root = link(l,r);
            root -> lk += 2;
            root->lb-=2*c[i];
        }
        else
        {
            w [i] = (i - 2) * a + 1;
            root = link(new node(w[i], 0, 0), root);
            root -> lz += b;
            root -> update();
            root -> lk += 2;
            root -> lb -= 2 * c[i];
        }
    }
    node *r = search(root), *l;
    cut(r, l);
    double x = r -> x - r -> y / r -> k;
    if (l) x = max(rest(l) -> x, x);
    if (x < (n - 1) * a + 1) x = (n - 1) * a + 1;
    if (x > q) x = q;
    for (int i = n; i; i --)
    {
        ans[i] = x;
        if (x - a < w[i]) x -= a;
        else if (x - b > w[i]) x -= b;
        else x = w[i];
    }
    double sum = 0;
    for (int i = 1; i <= n; i ++)
    {
        printf("%.10lf ",ans[i]);
        sum += (c[i] - ans[i]) * (c[i] - ans[i]);
    }
    printf("\n%.10lf\n",sum);
    return 0;
}