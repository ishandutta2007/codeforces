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


const int N = 1005;
int color[N];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    vector <int> need;

    int bstK = 2;
    int bst = -1;

    for (int k = 2; k <= n; k++)
    {
        int cnt = n / k;
        int cur = (cnt - 1) * (k - 1) + max(0, n % k - 1);
        if (cur > bst)
        {
            bst = cur;
            bstK = k;
        }
    }

    for (int i = 0; i < n; i++)
        if (i % bstK)
            need.push_back(i);

    while (true)
    {
        vector <int> bad;
        for (int x : need)
            if (color[x] == 0)
                bad.push_back(x);
        
        if ((int)bad.size() < bstK)
        {
            printf("0\n");
            fflush(stdout);
            break;
        }
        printf("%d", bstK);
        for (int i = 0; i < bstK; i++)
        {
            color[bad[i]] ^= 1;
            printf(" %d", bad[i] + 1);
        }
        printf("\n");
        fflush(stdout);
        int x;
        scanf("%d", &x);
        if (x == -1) throw;
        x--;
        for (int i = 0; i < bstK; i++)
            color[(x + i) % n] = 0;
    }


	return 0;
}