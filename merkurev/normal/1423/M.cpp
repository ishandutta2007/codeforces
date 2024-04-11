#ifndef LOCAL
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#endif

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
#include <queue>
#include <random>
#include <ctime>
#include <chrono>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif


typedef long long int int64;
typedef long long int ll;
typedef long long unsigned ull;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}


const int N = 1500;
int _a[N][N];

void init(int n, int m)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &_a[i][j]);
}

int _cnt = 0;

int force_ask(int x, int y)
{
    printf("? %d %d\n", x, y);
    fflush(stdout);
#ifdef LOCAL
    _cnt++;
    return _a[x][y];
#endif
    int ans;
    scanf("%d", &ans);
    return ans;
}

map <pair <int, int>, int> mem; 

int ask(int x, int y)
{
    if (mem.count(make_pair(x, y)) == 0)
        mem[make_pair(x, y)] = force_ask(x, y);
    return mem[make_pair(x, y)];
}

vector <int> reduce(vector <int> rows, vector <int> cols)
{
    vector <int> ans;
  
    eprintf("reduce\n");
    int i = 0;
    for (int c : cols)
    {
        eprintf("c = %d\n", c);
        if (ans.empty())
        {
            ans.push_back(c);
            continue;
        }
        while (!ans.empty() && ask(rows[i], ans.back()) > ask(rows[i], c))
        {
            ans.pop_back();
            i--;
        }
        if (ans.size() == rows.size())
            continue;
        else
        {
            ans.push_back(c);
            i++;
        }
    }
    eprintf("reduce end\n");

    return ans;
}

vector <int> solve(vector <int> rows, vector <int> cols)
{
    if ((int) cols.size() > (int) rows.size())
        cols = reduce(rows, cols);

    int n = (int) rows.size();
    int m = (int) cols.size();

    vector <int> nrows;
    for (int i = 1; i < n; i += 2)
        nrows.push_back(rows[i]);

    vector <int> nans;
    if (!nrows.empty())
        nans = solve(nrows, cols);

    vector <int> ans;
    int ptr = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 1)
        {
            ans.push_back(nans[i / 2]);
            continue;
        }
        int nptr = m - 1;
        if (i + 1 < n)
        {
            nptr = ptr;
            while (cols[nptr] < nans[i / 2])
                nptr++;
        }
        int bst = ptr;
        for (int j = ptr; j <= nptr; j++)
            if (ask(rows[i], cols[j]) < ask(rows[i], cols[bst]))
                bst = j;
        ans.push_back(cols[bst]);
        ptr = nptr;
    }
    return ans;
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);

#ifdef LOCAL
    init(n, m);
#endif

    vector <int> rows, cols;
    for (int i = 1; i <= n; i++)
        rows.push_back(i);
    for (int i = 1; i <= m; i++)
        cols.push_back(i);

    vector <int> mins = solve(rows, cols);

    int bst = 0;
    for (int i = 0; i < n; i++)
        if (ask(rows[i], mins[i]) < ask(rows[bst], mins[bst]))
            bst = i;

    eprintf("cnt = %d\n", _cnt);

    printf("! %d\n", ask(rows[bst], mins[bst]));
    fflush(stdout);

	return 0;
}