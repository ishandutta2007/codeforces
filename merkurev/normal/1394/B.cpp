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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int N = (int) 2e5 + 100;
vector <pair <int, int>> g[N];

const int CNT = 45;
int cnt[N][CNT];
long long bad[CNT];

int getId(int k, int i)
{
    int ans = 0;
    for (int j = 1; j < k; j++)
        ans += j;
    ans += i;
    return ans;
}

void add(int v, int k, int i)
{
    cnt[v][getId(k, i)]++;
}

void addEdge(int a, int b)
{
    bad[a] |= (1LL << b);
    bad[b] |= (1LL << a);
}


int ans;

vector <int> st;

void genAll(int cur, int k, long long maskbad)
{
    if (cur == k + 1)
    {
        ans++;
        return;
    }
    for (int i = 0; i < cur; i++)
    {
        int id = getId(cur, i);
        if ((maskbad | bad[id]) & (1LL << id))
            continue;
        st.push_back(i);
        genAll(cur + 1, k, maskbad | bad[id]);
        st.pop_back();
    }
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--;
        b--;
        g[a].emplace_back(c, b);
    }

    for (int i = 0; i < n; i++)
    {
        sort(g[i].begin(), g[i].end());
        int sz = (int) g[i].size();
        for (int j = 0; j < sz; j++)
        {
            //eprintf("%d(%d/%d) -> %d\n", i, j, sz, g[i][j].second);
            add(g[i][j].second, sz, j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int a = 0; a < CNT; a++)
        {
            if (cnt[i][a] > 1)
                addEdge(a, a);
            if (cnt[i][a] == 0)
                continue;
            for (int b = 0; b < CNT; b++)
                if (cnt[i][b] && b != a)
                    addEdge(a, b);
        }
    }

    genAll(1, k, 0LL);
    printf("%d\n", ans);

	return 0;
}