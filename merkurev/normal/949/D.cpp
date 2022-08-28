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
int a[N], x[N];
int need[N];
int n, d, b;

bool check()
{
    for (int i = 0; i < n; i++)
        x[i] = a[i];
    int m = (n + 1) / 2;
    int pos = 0;
    for (int i = 0; i < m; i++)
    {
        while (true)
        {
            int q = min(x[pos], need[i] );
            x[pos] -= q;
            need[i] -= q;

            if (q > 0)
            {
                int dst = abs(pos - i);
                int t = (dst + d - 1) / d;
                if (t > i + 1) return false;
            }

            if (need[i] > 0) pos++;
            else break;

        }
    }
    pos = n - 1;
    for (int i = n - 1; i >= m; i--)
    {
        while (true)
        {
            int q = min(x[pos], need[i] );
            x[pos] -= q;
            need[i] -= q;

            if (q > 0)
            {
                int dst = abs(pos - i);
                int t = (dst + d - 1) / d;
                if (t > (n - 1 - i) + 1) return false;
            }
            
            if (need[i] > 0) pos--;
            else break;
        }
    }
    return true;
}


int main(int , char *[] )
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
#endif

    scanf("%d%d%d", &n, &d, &b);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i] );

    int bl = -1, br = (n + 1) / 2;
    while (br - bl > 1)
    {
        int i = (bl + br) / 2;

        int l = i;
        int r = n - i - 1;
        memset(need, 0, sizeof need);
        for (int it = l; it <= r; it++)
            need[it] = b;
        if (check() )
            br = i;
        else
            bl = i;
    }
    printf("%d\n", br);
	return 0;
}