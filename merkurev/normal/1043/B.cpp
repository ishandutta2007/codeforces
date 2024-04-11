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
int a[N], x[N];
long long b[N];

void gen(int k, int n)
{
    b[0] = 0;
    for (int i = 1; i <= n; i++)
        b[i] = b[i - 1] + x[(i - 1) % k];
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++)
        x[i] = a[i + 1] - a[i];

    vector <int> ans;
    for (int k = 1; k <= n; k++)
    {
        gen(k, n);
        bool good = true;
        for (int i = 0; i <= n; i++)
            if (a[i] != b[i])
                good = false;
        if (good)
            ans.push_back(k);
    }
    printf("%d\n", (int) ans.size());
    for (int xx : ans)
        printf("%d ", xx);
    printf("\n");


	return 0;
}