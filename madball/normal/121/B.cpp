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

char ar[100500];

void solve()
{
    set<int> positions;
    int n, k;
    cin >> n >> k;
    For(i, n)
    {
        char c;
        cin >> c;
        ar[i] = c;
    }
    For(i, n - 1)
        if (ar[i] == '4' && ar[i + 1] == '7')
            positions.insert(i);
    while (k > 500500)
        k -= 64800;
    for (; k && !positions.empty(); --k)
    {
        int i = *positions.begin();
        positions.erase(positions.begin());
        if (i % 2)
        {
            ar[i] = '7';
            if (i && ar[i - 1] == '4')
                positions.insert(i - 1);
        }
        else
        {
            ar[i + 1] = '4';
            if (ar[i + 2] == '7')
                positions.insert(i + 1);
        }
    }
    For(i, n)
        putchar(ar[i]);
    putchar('\n');
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