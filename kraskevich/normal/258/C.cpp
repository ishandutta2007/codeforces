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
#define pii pair<int, int>

const int MOD = 1000 * 1000 * 1000 + 7;
const int N = 111111;
int a[N], n, l[N], dp[N];
vector<int> d[N];

void init()
{
    for (int i = 1; i < N; i++)
        for (int x = i; x < N; x += i)
            d[x].push_back(i);
    for (int i = 1; i < N; i++)
    {
        if (lower_bound(a, a + n, i) >= a + n)
            l[i] = -1;
        else
            l[i] = lower_bound(a, a + n, i) - a;
    }
}

int bpow(int x, int p)
{
    int r = 1;
    while (p)
    {
        if (p % 2)
            r = r * 1ll * x % MOD;
        x = x * 1ll * x % MOD;
        p /= 2;
    }
    return r;
}

int pos[N];
int sz;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    init();
    int res = 0;
    for (int i = 1; i <= N; i++)
    {
        if (l[i] == -1)
            break;
        sz = 0;
        int cur = 1;
        if (i > 1)
        {
            for (int x: d[i])
                pos[sz++] = l[x];
            for (int j = 0; j < sz - 1; j++)
                cur = cur * 1ll * bpow((j + 1), pos[j + 1] - pos[j]) % MOD;
            cur = cur * 1ll * ((bpow(sz, n - pos[sz - 1]) - bpow(sz - 1, n - pos[sz - 1]) + MOD) % MOD) % MOD;
        }
        //cout << i << " " << cur << endl;
        res += cur;
        res %= MOD;
    }
    cout << res;

    return 0;
}