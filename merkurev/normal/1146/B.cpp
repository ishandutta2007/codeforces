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


const int N = (int) 1e5 + 100;
char str[N];

const int ALP = 26;
int cnt[ALP];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


    scanf("%s", str);
    int n = strlen(str);
    for (int i = 0; i < n; i++)
        cnt[str[i] - 'a']++;

    int k = n - cnt[0];
    if (k % 2 != 0)
    {
        printf(":(\n");
        return 0;
    }
    k /= 2;
    k += cnt[0];
    int ptr = k;
    for (int i = 0; i < k; i++)
        if (str[i] != 'a')
        {
            if (str[i] != str[ptr])
            {
                printf(":(\n");
                return 0;
            }
            ptr++;
        }
    if (ptr != n)
    {
        printf(":(\n");
        return 0;
    }
    str[k] = 0;
    printf("%s", str);

	return 0;
}