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
    string s;
    getline(cin, s);
    static int rev[256];
    For(i, 8)
        rev[1 << (7 - i)] = 1 << i;
    For(i, 256)
        rev[i] = rev[i & (-i)] | rev[i & (i - 1)];
    int prv = 0;
    for (auto c : s)
    {
        prv = prv - rev[c];
        prv += 256;
        prv %= 256;
        cout << prv << '\n';
        prv = rev[c];
    }
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