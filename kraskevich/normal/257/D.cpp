#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>
#include <ctime>
#include <ctype.h>

using namespace std;


const int N = 100 * 1000 + 10;
long long a[N];
char sign[N];

long long ABS(long long a)
{
    if (a >= 0)
        return a;
    else
        return -a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", & n);
    for (int i = 0; i < n; ++i)
        scanf("%I64d", & a[i]);

    long long sum = 0;

    for (int i = n - 1; i >= 0; --i)
        if (ABS(sum - a[i]) <= ABS(sum + a[i]))
        {
            sum -= a[i];
            sign[i] = '-';
        }
        else
        {
            sum += a[i];
            sign[i] = '+';
        }

    if (sum < 0)
        for (int i = 0; i < n; ++i)
            if (sign[i] == '-')
                sign[i] = '+';
            else
                sign[i] = '-';

    for (int i = 0; i < n; ++i)
        printf("%c", sign[i]);

    return 0;
}