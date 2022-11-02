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

#define F first
#define S second
#define MP make_pair
#define pii pair<long long, long long>

const int N = 10 * 1000 * 1000 + 10;
vector<bool> pr(N, true);
int sum[N];
int k;
vector<pii> have;

void init()
{
    fill(sum, sum + N, 0);
    pr[0] = pr[1] = false;
    for (int i = 2; i * i < N; i++)
        if (pr[i])
            for (int j = i * i; j < N; j += i)
                pr[j] = false;
}

long long get_sum(int l, int r)
{
    if (r > N - 1)
        r = N - 1;
    return sum[r] - sum[l - 1];
}

long long work(int x)
{
    int l = 0;
    int r = x - 1;
    long long tot = 0;
    for (;;)
    {
        long long cnt = r / x;
        cnt = cnt * get_sum(l, r);
        tot += cnt;
        l += x;
        r += x;
        if (l >= N - 1)
            break;
    }
    return tot;
}

long long cnt(long long x, long long p)
{
    long long res = 0;
    long long st = p;
    for(;;)
    {
        res += x / p;
        if (x / st + 1 < p)
            break;
        p *= st;
        if (p > x)
            break;
    }
    return res;
}

bool check(long long x)
{
    for (int i = 0; i < have.size(); ++i)
    {
        long long cur = cnt(x, have[i].F);
        if (cur < have[i].S)
            return false;
    }
    return true;
}

void solve()
{
    init();

    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        int a;
        scanf("%d", &a);
        ++sum[a];
    }
    for (int i = 1; i < N; ++i)
        sum[i] += sum[i - 1];

    for (int i = 2; i < N; ++i)
    {
        if (!pr[i])
            continue;
        long long x = i;
        long long f = 0;
        for (;;)
        {
            f += work(x);
            x = x * i;
            if (x >= N)
                break;
        }
        have.push_back(pii(i, f));
    }

    long long l = 1;
    long long r = (long long)2e18 + 10;
    while (l < r)
    {
        long long m = (l + r) / 2;
        if (check(m))
            r = m;
        else
            l = m + 1;
    }

    printf("%I64d", l);
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}