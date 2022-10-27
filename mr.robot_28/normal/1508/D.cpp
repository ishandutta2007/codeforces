#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
struct point{
    ll x, y;
    point(ll _x = 0, ll _y = 0): x(_x), y(_y){}
    point operator-(const point &o)const {return point(x - o.x, y - o.y);}
    int half()
    {
        return y < 0 || (y == 0 &&x < 0);
    }
};
ll cross(point p, point q)
{
    return p.x * q.y - p.y * q.x;
}
bool cmp(point a, point b)
{
    if(a.half() != b.half())
    {
        return a.half() < b.half();
    }
    return cross(a, b) > 0;
}
const int MAXN = 2005;
point ps[MAXN];
int n, a[MAXN], cyc[MAXN];
vector <int> in_cyc[MAXN];
vector <pair <int, int> > ops;
int piv;
bool cmp1(int i, int j)
{
    return cmp(ps[i] - ps[piv], ps[j] - ps[piv]);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> ps[i].x >> ps[i].y >> a[i];
    }
    int cur_cyc = 0;
    piv = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == i || cyc[i])
        {
            continue;
        }
        cur_cyc++;
        int u = i;
        do{
            cyc[u] = cur_cyc;
            in_cyc[cur_cyc].push_back(u);
            u = a[u];
        }while(!cyc[u]);
        piv = i;
    }
    vector <int> to_sort;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == i || i == piv)
        {
            continue;
        }
        to_sort.push_back(i);
    }
    if(sz(to_sort) == 0)
    {
        cout << 0;
        return 0;
    }
    sort(to_sort.begin(), to_sort.end(), cmp1);
    vector <pair <int, int> > pairs;
    for(int i = 0; i + 1 < sz(to_sort); i++)
    {
        if(cross(ps[to_sort[i]] - ps[piv], ps[to_sort[i + 1]] - ps[piv]) > 0)
        {
            pairs.push_back({to_sort[i], to_sort[i + 1]});
        }
    }
    for(auto p : pairs)
    {
        int c1 = cyc[p.X];
        int c2 = cyc[p.Y];
        if(c1 != c2)
        {
            for(auto &x : in_cyc[c2])
            {
                cyc[x]= c1;
                in_cyc[c1].push_back(x);
            }
            in_cyc[c2].clear();
            ops.push_back({p.X, p.Y});
            swap(a[p.X], a[p.Y]);
        }
    }
    while(a[piv] != piv)
    {
        int u = a[piv];
        ops.push_back({piv, u});
        swap(a[piv], a[u]);
    }
    cout << sz(ops) << "\n";
    for(auto p : ops)
    {
        cout << p.X << " " << p.Y << "\n";
    }
    return 0;
}