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


const int N = 605;
int _g[N][N];
int _n;
void _init()
{
    int n, m;
    scanf("%d%d", &n, &m);
    _n = n;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        _g[a][b] = 1;
        _g[b][a] = 1;
    }
}
int _ask(vector <int> v)
{
    int ans = 0;
    for (int a : v)
        for (int b : v)
            ans += _g[a][b];
    ans /= 2;
    return ans;
}
void _testN(vector <int> v)
{
    if ((int) v.size() < 3 || (int) v.size() % 2 == 0) throw;
    v.push_back(v[0]);
    for (int i = 0; i + 1 < (int) v.size(); i++)
        if (!_g[v[i]][v[i + 1]]) throw;
}
void _testY(vector <int> a, vector <int> b)
{
    if (_ask(a) != 0 || _ask(b) != 0) throw;
}

int used[N];
vector <int> g[N];

int n;



int ask(vector <int> v)
{
    if ((int) v.size() <= 1) return 0;

    printf("? %d", (int) v.size());
    for (int x : v)
        printf(" %d", x + 1);
    printf("\n");
    fflush(stdout);

#ifdef LOCAL
    return _ask(v);
#endif

    int ans;
    scanf("%d", &ans);
    return ans;
}

int ask(int a, vector <int> b)
{
    int ans = -ask(b);
    b.push_back(a);
    ans += ask(b);
    eprintf("ask ans = %d\n", ans);
    return ans;
}

int getEdge(int v)
{
    vector <int> vs;
    for (int i = 0; i < n; i++)
        if (!used[i])
            vs.push_back(i);

    if (ask(v, vs) == 0) return -1;

    eprintf("---\n");
    int l = 0, r = (int) vs.size();
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        vector <int> cur;
        for (int i = 0; i < m; i++)
            cur.push_back(vs[i]);
        if (ask(v, cur) > 0)
            r = m;
        else
            l = m;
        eprintf("l = %d, r = %d\n", l, r);
    }
    return vs[r - 1];
}

void dfs(int v, int c)
{
    eprintf("v = %d, c = %d\n", v, c);
    used[v] = c;
    while (true)
    {
        int to = getEdge(v);
        eprintf("found edge: %d -> %d\n", v, to);
        if (to == -1) break;
        g[v].push_back(to);
        g[to].push_back(v);
        dfs(to, c ^ 3);
    }
}


vector <int> comp[3];

vector <int> st;
void dfsC(int v, int t)
{
    st.push_back(v);
    used[v] = true;
    if (v == t)
    {
        printf("N %d\n", (int) st.size());
        for (int x : st)
            printf("%d ", x + 1);
        printf("\n");
        fflush(stdout);
#ifdef LOCAL
        _testN(st);
#endif
        return;
    }
    for (int to : g[v])
        if (!used[to])
            dfsC(to, t);
    st.pop_back();
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
    _init();
    //	freopen("output.txt", "w", stdout);
#endif

    scanf("%d", &n);
#ifdef LOCAL
    n = _n;
#endif
    for (int i = 0; i < n; i++)
    {    
        if (!used[i])
            dfs(i, 1);
    }
    for (int i = 0; i < n; i++)
        comp[used[i] ].push_back(i);
    for (int t = 1; t <= 2; t++)
    {
        if (ask(comp[t]) != 0)
        {
            for (int it = 0; it < 2; it++)
            {
                while (true)
                {
                    int x = comp[t].back();
                    comp[t].pop_back();
                    if (ask(comp[t]) == 0)
                    {
                        comp[t].push_back(x);
                        break;
                    }
                }
                reverse(comp[t].begin(), comp[t].end());
            }
            memset(used, 0, sizeof used);
            dfsC(comp[t][0], comp[t].back());

            return 0;
        }
    }
    printf("Y %d\n", (int) comp[1].size());
    for (int x : comp[1])
        printf("%d ", x + 1);
    printf("\n");
    fflush(stdout);

#ifdef LOCAL
    _testY(comp[1], comp[2]);
#endif

	return 0;
}