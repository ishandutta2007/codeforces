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

const int N = (int) 1e5 + 100;
vector <int> g[N], rg[N];
int a[N], cntGo[N];
bool lose[N], win[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++)
    {
        for (int j = i % a[i]; j < n; j += a[i])
            if (a[j] > a[i])
            {
                g[i].push_back(j);
                rg[j].push_back(i);
            }
    }

    vector <int> qu;
    for (int i = 0; i < n; i++)
    {
        cntGo[i] = (int) g[i].size();
        if ((int) g[i].empty())
        {
            lose[i] = true;
            qu.push_back(i);
        }
    }

    while (!qu.empty())
    {
        int v = qu.back();
        qu.pop_back();

        if (lose[v])
        {
            for (int x : rg[v])
            {
                if (win[x] ) continue;
                win[x] = true;
                qu.push_back(x);
            }
        }
        else if (win[v] )
        {
            for (int x : rg[v])
            {
                cntGo[x]--;
                if (cntGo[x] == 0 && !win[x])
                {
                    lose[x] = true;
                    qu.push_back(x);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (win[i])
            printf("A");
        else
            printf("B");
    printf("\n");


	return 0;
}