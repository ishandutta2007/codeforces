#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <random>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> ar1, ar2;
    For(i, n) For(j, n)
    {
        if ((i + j) % 2)
            ar1.emplace_back(i, j);
        else
            ar2.emplace_back(i, j);
    }
    For(i, n * n)
    {
        int a;
        cin >> a;
        int x = -1, y = -1, c = -1;
        if (ar1.empty())
        {
            tie(x, y) = ar2.back();
            ar2.pop_back();
            c = a == 2 ? 3 : 2;
        }
        else if (ar2.empty())
        {
            tie(x, y) = ar1.back();
            ar1.pop_back();
            c = a == 1 ? 3 : 1;
        }
        else if (a == 1)
        {
            tie(x, y) = ar2.back();
            ar2.pop_back();
            c = 2;
        }
        else
        {
            tie(x, y) = ar1.back();
            ar1.pop_back();
            c = 1;
        }
        cout << c << ' ' << x + 1 << ' ' << y + 1 << endl;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}