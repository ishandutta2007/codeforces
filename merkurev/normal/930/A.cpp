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
int h[N], p[N], cnt[N];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &p[i] );
        p[i]--;
        h[i] = h[p[i] ] + 1;
        cnt[h[i] ] ^= 1;
    }
    int ans = 1;
    for (int i = 0; i <= n; i++)
        ans += cnt[i];
    printf("%d\n", ans);

	return 0;
}