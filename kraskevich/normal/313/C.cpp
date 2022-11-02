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

using namespace std;

const int N = 2 * 1000 * 1000 + 6;
int res[2000][2000];
int a[N];
int b[N];
int n;

long long solve(int lx, int ly, int rx, int ry, int ptrL, int ptrR)
{
    if (lx == rx)
    {
        res[lx][ly] = a[ptrL];
        return res[lx][ly];
    }
    int len = ptrR - ptrL + 1;
    int side = (rx - lx + 1);
    for (int i = 0; i < len; i++)
    {
        b[i / 4 + (i % 4) * (len / 4)] = a[i + ptrL];
    }
    for (int i = 0; i < len; i++)
        a[i + ptrL] = b[i];
    long long ret = a[ptrR];
    ret += solve(lx, ly, lx + side / 2 - 1, ly + side / 2 - 1, ptrL, ptrL + len / 4 - 1);
    ret += solve(lx + side / 2, ly, rx, ly + side / 2 - 1, ptrL + len / 4, ptrL + 2 * (len / 4) - 1);
    ret += solve(lx, ly + side / 2, lx + side / 2 - 1, ry, ptrL + 2 * (len / 4), ptrL + 3 * (len / 4) - 1);
    ret += solve(lx + side / 2, ly + side / 2, rx, ry, ptrL + 3 * (len / 4), ptrL + 4 * (len / 4) - 1);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int m = 1;
    while (m * m < n)
        m++;
    printf("%I64d\n", solve(0, 0, m - 1, m - 1, 0, n - 1));


    return 0;
}