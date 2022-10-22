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

lint mod(lint a, lint b)
{
    a %= b;
    if (a < 0)
        a += b;
    return a;
}

lint div_down(lint a, lint b)
{
    return (a - mod(a, b)) / b;
}

pair<lint, lint> convert(lint a, lint b, lint x, lint y)
{
    return { div_down(x + y, 2 * a), div_down(x - y, 2 * b) };
}

void solve()
{
    lint a, b, x1, y1, x2, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    tie(x1, y1) = convert(a, b, x1, y1);
    tie(x2, y2) = convert(a, b, x2, y2);
    cout << max(abs(x1 - x2), abs(y1 - y2)) << '\n';
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