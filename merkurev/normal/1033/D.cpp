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

const int MOD = 998244353;//(int) 1e9 + 7;
void smul(int &a, int b)
{
    a = (a * 1LL * b) % MOD;
}

long long fpow(long long x, int n)
{
    long long ans = 1;
    for (int i = 0; i < n; i++)
        ans *= x;
    return ans;
}
long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}
long long root(long long a, int deg)
{
    long long x = pow((double)a, 1. / (double) deg) - 4.;
    x = max(x, 0LL);
    while (fpow(x, deg) < a) x++;
    if (fpow(x, deg) == a) return x;
    return -1;
}

const int N = 505;
long long a[N];
set <long long> sa, sx;
vector <long long> nums;
map <long long, int> m;
vector <int> bad;


void addX(long long x)
{
    if (!sx.count(x))
    {
//        eprintf("add : %lld\n", x);
        sx.insert(x);
        nums.push_back(x);
        bad.push_back(0);
    }
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    sx.insert(1);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        sa.insert(a[i]);
        addX(a[i]);
    }
    for (int i = 0; i < (int) nums.size(); i++)
    {
        long long x = nums[i];
        for (int deg = 4; deg >= 2; deg--)
        {
            long long r = root(x, deg);
            if (r != -1) 
            {
                bad[i] = 1;
                addX(r);
                break;
            }
        }
        for (int j = 0; j < i; j++)
        {
            if (bad[j] || bad[i]) continue;
            long long g = gcd(nums[j], x);
            if (g != nums[j] && g != 1) bad[j] = 1;
            if (g != nums[i] && g != 1) bad[i] = 1;
            addX(g);
            addX(nums[j] / g);
            addX(nums[i] / g);
        }
    }
/*
    for (int j = 0; j < (int) nums.size(); j++)
    {
        if (bad[j]) eprintf("--");
        eprintf("%lld ", nums[j]);
        
    }
    eprintf("\n");
*/
    for (int i = 0; i < n; i++)
    {
        long long x = a[i];
        for (int j = 0; j < (int) nums.size(); j++)
        {
            if (bad[j]) continue;
            long long y = nums[j];
            while (x % y == 0)
            {
             //   eprintf("y = %lld\n", y);
                m[y]++;
                x /= y;
            }
        }
        if (x != 1)
            m[x]++;
    }
    int ans = 1;
    for (auto p : m)
    {
        if (sa.count(p.first))
        {
            smul(ans, p.second + 1);
            smul(ans, p.second + 1);
        }
        else
        {
            smul(ans, p.second + 1);
        }
    }
    printf("%d\n", ans);

	return 0;
}