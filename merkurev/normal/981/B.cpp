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


map <int, int> c;

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    for (int t = 0; t < 2; t++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            c[a] = max(c[a], b);
        }
    }
    long long ans = 0;
    for (auto p : c)
        ans += p.second;
    printf("%lld\n", ans);


	return 0;
}