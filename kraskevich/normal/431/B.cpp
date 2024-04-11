#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long LL;
typedef long double ld;
#define MP make_pair
#define F first
#define S second


int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n = 5;
    vector<vector<int> > g(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    int res = 0;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i = 0; i < 1000; i++)
    {
        int cur = 0;
        for (int s = 0; s < 5; s++)
            for (int f = s; f + 1 < 5; f += 2)
                cur += g[p[f + 1]][p[f]] + g[p[f]][p[f + 1]];
        res = max(res, cur);
        next_permutation(p.begin(), p.end());
    }
    cout << res;

    return 0;
}