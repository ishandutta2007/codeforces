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
    lint n, k;
    int p;
    cin >> n >> k >> p;
    For(i, p)
    {
        lint a;
        cin >> a;
        a = n - a;
        if (k == 0)
            cout << '.';
        else if (k == n)
            cout << 'X';
        else if (n % 2 == 0)
        {
            if (k * 2 >= n)
                cout << (a % 2 == 0 || a + 1 <= k * 2 - n ? 'X' : '.');
            else
                cout << (a % 2 == 0 && k * 2 > a ? 'X' : '.');
        }
        else if (a == 0)
            cout << 'X';
        else
        {
            --a;
            --n;
            --k;
            if (k * 2 >= n)
                cout << (a % 2 == 0 || a + 1 <= k * 2 - n ? 'X' : '.');
            else
                cout << (a % 2 == 0 && k * 2 > a ? 'X' : '.');
            ++n;
            ++k;
        }
    }
    cout << '\n';

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}