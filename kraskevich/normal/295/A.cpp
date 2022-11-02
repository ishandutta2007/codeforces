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

#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second
#define MP make_pair

const int N = 100 * 1000 + 10;
long long a[N];
long long add[N];
long long op[N];
long long opAdd[N];
long long l[N], r[N], d[N];

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    fill(add, add + N, 0);
    fill(op, op + N, 0);
    fill(opAdd, opAdd + N, 0);

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
    {
        cin >> l[i] >> r[i] >> d[i];
        --l[i];
    }
    for (int i = 0; i < k; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x;
        ++opAdd[x];
        --opAdd[y];
    }

    long long curr = 0;
    for (int i = 0; i < m; ++i)
    {
        curr += opAdd[i];
        op[i] = curr;
    }
    for (int i = 0; i < m; ++i)
    {
        add[l[i]] += op[i] * d[i];
        add[r[i]] -= op[i] * d[i];
    }
    curr = 0;
    for (int i = 0; i < n; ++i)
    {
        curr += add[i];
        cout << a[i] + curr << " ";
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}