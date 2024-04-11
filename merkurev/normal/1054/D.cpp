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
int a[N];

map <int, int> m;

long long sq(int x)
{
    return x * 1LL * (x - 1) / 2;
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, k;
    scanf("%d%d", &n, &k);
    int mask = (1 << k) - 1;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int x = 0;
    m[x]++;
    for (int i = 0; i < n; i++)
    {
        x ^= a[i];
        if (x & 1)
            x ^= mask;
        m[x]++;
    }
    long long ans = 0;
    for (auto p : m)
        ans += sq((p.second + 1) / 2) + sq(p.second / 2);
    printf("%lld\n", sq(n + 1) -  ans);




	return 0;
}