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

const int N = 2005;
string codes[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string s[N];
pair <int, int> cb[N][N];
char str[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        s[i] = string(str);
    }
    memset(cb, -1, sizeof cb);
    cb[n][k] = make_pair(0, 0);
    for (int i = n - 1; i >= 0; i--)
        for (int rk = 0; rk <= k; rk++)
        {
            if (cb[i + 1][rk].first == -1)
                continue;
            for (int d = 0; d <= 9; d++)
            {
                int need = 0;
                for (int j = 0; j < 7; j++)
                {
                    if (codes[d][j] == s[i][j])
                        continue;
                    if (s[i][j] == '1')
                    {
                        need = N;
                        break;
                    }
                    need++;
                }
                if (need > rk)
                    continue;
                int nk = rk - need;
                cb[i][nk] = max(cb[i][nk], make_pair(d, rk));
            }
        }
    if (cb[0][0].first == -1)
    {
        printf("-1\n");
        return 0;
    }
    int ck = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%d", cb[i][ck].first);
        ck = cb[i][ck].second;
    }
    printf("\n");


	return 0;
}