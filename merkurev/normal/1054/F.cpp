#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


map <int, vector <int>> xs, ys;

struct Seg
{
    int x1, y1, x2, y2;
    Seg(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

    void print()
    {
        printf("%d %d %d %d\n", x1, y1, x2, y2);
    }
};

const int N = 1005;
vector <Seg> hor, ver, hort, vert;
vector <int> g[N];
int used[N];
int mt[N], rmt[N];

bool kuhn(int v)
{
    used[v] = true;
    for (int to : g[v])
    {
        int nv = mt[to];
        if (nv == -1 || (!used[nv] && kuhn(nv)))
        {
            mt[to] = v;
            rmt[v] = to;
            return true;
        }
    }
    return false;
}

bool cmpH(Seg h1, Seg h2)
{
    if (h1.y1 != h2.y1) return h1.y1 < h2.y1;
    return make_pair(h1.x1, h1.x2) < make_pair(h2.x1, h2.x2);
}

bool cmpV(Seg v1, Seg v2)
{
    if (v1.x1 != v2.x1) return v1.x1 < v2.x1;
    return make_pair(v1.y1, v1.y2) < make_pair(v2.y1, v2.y2);
}

bool interHV(Seg h, Seg v)
{
    return h.x1 < v.x1 && v.x2 < h.x2 && v.y1 < h.y1 && h.y2 < v.y2;
}

void printSegs(vector <Seg> v)
{
    vector <Seg> ans;
    for (int i = 0; i < (int) v.size(); i++)
        if (!ans.empty() && ans.back().x2 == v[i].x1 && ans.back().y2 == v[i].y1)
        {
            ans.back().x2 = v[i].x2;
            ans.back().y2 = v[i].y2;
        }
        else
            ans.push_back(v[i]);
    printf("%d\n", (int) ans.size());
    for (auto x : ans)
        x.print();
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        ys[x].push_back(y);
        xs[y].push_back(x);
    }
    for (auto p : xs)
    {
        int y = p.first;
        auto v = p.second;
        sort(v.begin(), v.end());
        for (int i = 0; i < (int) v.size(); i++)
            hort.emplace_back(v[i], y, v[i], y);
        for (int i = 0; i + 1 < (int) v.size(); i++)
        {
            int x1 = v[i], x2 = v[i + 1];
            hor.emplace_back(x1, y, x2, y);
        }
    }
    for (auto p : ys)
    {
        int x = p.first;
        auto v = p.second;
        sort(v.begin(), v.end());
        for (int i = 0; i < (int) v.size(); i++)
            vert.emplace_back(x, v[i], x, v[i]);
        for (int i = 0; i + 1 < (int) v.size(); i++)
        {
            int y1 = v[i], y2 = v[i + 1];
            ver.emplace_back(x, y1, x, y2);
        }
    }
    for (int i = 0; i < (int) hor.size(); i++)
        for (int j = 0; j < (int) ver.size(); j++)
        {
            if (interHV(hor[i], ver[j]))
            {
                g[i].push_back(j);
            }
        }

    memset(mt, -1, sizeof mt);
    memset(rmt, -1, sizeof rmt);
    while (true)
    {
        bool ch = false;
        memset(used, false, sizeof used);
        for (int i = 0; i < (int) hor.size(); i++)
            if (rmt[i] == -1 && kuhn(i))
                ch = true;
        if (!ch) break;
    }

    for (int i = 0; i < (int) hor.size(); i++)
        if (used[i])
            hort.push_back(hor[i]);
    for (int i = 0; i < (int) ver.size(); i++)
        if (mt[i] == -1 || !used[mt[i]])
            vert.push_back(ver[i]);

    sort(hort.begin(), hort.end(), cmpH);
    sort(vert.begin(), vert.end(), cmpV);

    printSegs(hort);
    printSegs(vert);

	return 0;
}