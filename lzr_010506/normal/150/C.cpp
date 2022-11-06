#include <bits/stdc++.h>
using namespace std;

const int N = 150009;

struct segTree
{
    int l,r;
    double lmx,rmx,mx,sum;
} T[N << 2];

int n,m;
double C,x[N],p[N],ps[N],ep[N];
pair<int, int> in[N << 1];

inline int ls(int x) {return x << 1;}
inline int rs(int x) {return (x << 1) | 1;}

void update(segTree s1, segTree s2, segTree &cur)
{
    cur.sum = s1.sum + s2.sum;
    cur.mx = max(max(s1.mx, s2.mx), s1.rmx + s2.lmx);
    cur.lmx = max(s1.lmx, s1.sum + s2.lmx);
    cur.rmx = max(s2.rmx, s2.sum + s1.rmx);
}

void build(int l,int r,int i)
{
    T[i].l = l;
    T[i].r = r;
    if (l < r)
    {
        int mid = (l + r) >> 1;
        build(l, mid, ls(i));
        build(mid + 1, r, rs(i));
        update(T[ls(i)],T[rs(i)],T[i]);
    }
    else
    {
        T[i].sum = ep[r];
        T[i].mx = T[i].lmx = T[i].rmx = max(0.0, ep[r]);
    }
}

segTree query(int l,int r,int i)
{
    if (l == T[i].l && r == T[i].r) return T[i];
    int mid = (T[i].l + T[i].r) >> 1;
    if (l > mid) return query(l, r, rs(i));
    if (r <= mid) return query(l, r ,ls(i));
    segTree s1 = query(l, mid, ls(i));
    segTree s2 = query(mid + 1, r, rs(i));
    segTree ret;
    update(s1, s2, ret);
    return ret;
}


int main()
{
    scanf("%d%d%lf",&n,&m,&C);
    for (int i = 1; i <= n; i ++)
    	scanf("%lf", &x[i]);
    for (int i = n; i >= 2; i --)
    	x[i] = x[i] - x[i - 1];
    for (int i = 2; i <= n; i ++)
    	scanf("%lf",&p[i]), p[i] /= 100.0;
    for (int i = 1; i <= m; i ++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        in[i] = make_pair(l + 1, r);
    }
    for (int i = 2; i <= n; i ++)
    	ep[i] = x[i] / 2.0 - C * p[i];
    build(2, n, 1);
    double ans = 0;
    for (int i = 1; i <= m; i ++)
        ans += query(in[i].first, in[i].second, 1).mx;
    printf("%.9f\n",ans);
    return 0;
}