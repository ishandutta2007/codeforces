#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
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

const int N = 2 * 100 * 1000 + 10;
long long s[N];
long long add[N];
long long a[N];
long long b[N];
set< pll > pos;
int l[N];
int r[N];

void solve()
{
    fill(add, add + N, 0);
    fill(s, s + N, 0);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < q; ++i)
    {
        cin >> l[i] >> r[i];
        --l[i];
        --r[i];
        add[l[i]]++;
        add[r[i] + 1]--;
    }

    long long curs = 0;
    for (int i = 0; i < n; ++i)
    {
        curs += add[i];
        s[i] = curs;
    }

    sort(a, a + n);
    for (int i = 0; i < n; ++i)
        pos.insert(pll(s[i], i));

    for (int i = n - 1; i >= 0; --i)
    {
        set< pll >::iterator it = pos.end();
        --it;
        b[it->S] = a[i];
        pos.erase(it);
    }

    long long res = 0;
    for (int i = 1; i < n; ++i)
        b[i] += b[i - 1];
    for (int i = 0; i < q; ++i)
    {
        res += b[r[i]];
        if (l[i])
            res -= b[l[i] - 1];
    }

    cout << res;

}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}