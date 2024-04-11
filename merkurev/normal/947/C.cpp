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

const int N = (int) 3e5 + 100;
const int LOG = 30;
int a[N], p[N];

const int SZ = N * LOG;
int goTo[SZ][2];
int cnt[SZ];
int par[SZ];
int sz = 1;

void addWord(int x)
{
    int v = 0;
    for (int i = LOG - 1; i >= 0; i--)
    {
        int c = ((x >> i) & 1);
        if (goTo[v][c] == 0)
        {
            par[sz] = v;
            goTo[v][c] = sz++;
        }
        v = goTo[v][c];
        cnt[v]++;
    }
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
        scanf("%d", &a[i] );
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i] );
        addWord(p[i] );
    }
    for (int i = 0; i < n; i++)
    {
        int v = 0;
        int ans = 0;
        for (int j = LOG - 1; j >= 0; j--)
        {
            int c = ((a[i] >> j) & 1);
            int nv = goTo[v][c];
            ans *= 2;
            if (nv != 0 && cnt[nv] != 0)
            {
                v = nv;
            }
            else
            {
                ans += 1;
                v = goTo[v][c ^ 1];
            }
        }
        printf("%d ", ans);
        while (v > 0)
        {
            cnt[v]--;
            v = par[v];
        }
    }


	return 0;
}