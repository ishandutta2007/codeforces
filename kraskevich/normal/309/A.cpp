#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <sstream>

using namespace std;

const int N = 2000 * 1000 + 10;
long long a[N];
long long n, l, t;

int main()
{
    scanf("%I64d%I64d%I64d", &n, &l, &t);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);

    for (int i = 0; i < n; i++)
        a[n + i] = a[i] + l;

    t *= 2;

    double res = 0;
    int ptr = 0;

    for (int i = 0; i < n; i++)
    {
        long long whole = t / l;
        res += whole * 1.0 * (n - 1) * 0.25;
        long long rem = t % l;
        for (;;)
        {
            int nxt = ptr + 1;
            if (nxt >= 2 * n)
                break;
            long long d = a[nxt] - a[i];
            if (d <= rem)
                ptr = nxt;
            else
                break;
        }
        int cnt = ptr - i;
        res += cnt * 0.25;
    }

    printf("%.10f", (float)res);

    return 0;
}