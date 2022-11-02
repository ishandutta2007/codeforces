#include <algorithm>
#include <iostream>
#include <string.h>
#include <memory.h>
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

const long long MOD = 1000 * 1000 * 1000;
const int N = 100 * 1000;

long long a[N];
int f[N];
int n, m;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    f[0] = f[1] = 1;
    for (int i = 2; i < N; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        f[i] %= MOD;
    }

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, v;
            cin >> x >> v;
            --x;
            a[x] = v;
        }
        if (t == 3)
        {
            int l, r, d;
            cin >> l >> r >> d;
            --l;
            --r;
            for (int j = l; j <= r; j++)
                a[j] += d, a[j] %= MOD;
        }
        if (t == 2)
        {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            long long s = 0;
            for (int j = 0; j <= r - l; j++)
                s += a[j + l] * f[j], s %= MOD;
            cout << s << endl;
        }
    }

    return 0;
}