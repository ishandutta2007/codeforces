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
int m[N];
int cnt[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &m[i] );

    cnt[0] = 1;
    for (int i = n; i > 0; i--)
        cnt[i - 1] = max(m[i - 1] + 1, cnt[i] - 1);
    for (int i = 0; i < n; i++)
        cnt[i + 1] = max(cnt[i + 1], cnt[i] );

    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += cnt[i] - m[i] - 1;

    printf("%lld\n", ans);


	return 0;
}