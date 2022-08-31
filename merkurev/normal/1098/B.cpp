#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
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

const int INF = (int) 1e9 + 100;
const int N = 300500;
int n, m;
char str[N];

struct Field
{
    string f[N];

    Field() : f() {}
    Field(int _n, int _m) : f()
    {
        for (int i = 0; i < _n; i++)
            f[i].resize(_m);
    }

    Field rotate() const
    {
        Field ans = Field();
        for (int i = 0; i < m; i++)
            ans.f[i].resize(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans.f[j][i] = f[i][j];
        return ans;
    }

    void read()
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s", str);
            f[i] = string(str);
        }
    }

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            printf("%s\n", f[i].c_str());
        }
        printf("\n");
    }
};

Field F;


char chs[5] = "ACGT";


pair <int, Field> solve()
{
    int bst = INF;
    Field bstF;

    do
    {
        Field curF = Field(n, m);
        int cur = 0;
        for (int i = 0; i < m; i++)
        {
            curF.f[0][i] = chs[i % 2];
            curF.f[1][i] = chs[i % 2 + 2];
            if (curF.f[0][i] != F.f[0][i])
                cur++;
            if (curF.f[1][i] != F.f[1][i])
                cur++;
        }
        for (int i = 2; i < n; i++)
        {
            int x[2] = {0, 0};
            for (int t = 0; t < 2; t++)
            {
                for (int j = 0; j < m; j++)
                    if (F.f[i][j] != curF.f[i % 2][(j % 2) ^ t])
                        x[t]++;
            }
            int xt = 0;
            if (x[1] < x[0])
                xt = 1;
            for (int j = 0; j < m; j++)
                curF.f[i][j] = curF.f[i % 2][(j % 2) ^ xt];
            cur += x[xt];
        }
        if (cur < bst)
        {
            bst = cur;
            bstF = curF;
        }
    }
    while (next_permutation(chs, chs + 4));

    return make_pair(bst, bstF);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%d%d", &n, &m);
    F.read();


    pair<int, Field> ans1 = solve();

    F = F.rotate();
    swap(n, m);

    pair<int, Field> ans2 = solve();

    ans2.second = ans2.second.rotate();
    //F = F.rotate();
    swap(n, m);

    //eprintf("%d %d\n", ans1.first, ans2.first);

    if (ans1.first < ans2.first)
        ans1.second.print();
    else
        ans2.second.print();

	return 0;
}