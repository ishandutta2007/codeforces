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

vector<int> ar;
void solve()
{
    int n;
    scanf("%d", &n);
    ar.resize(n);
    For(i, n)
        scanf("%d", &ar[i]);
    for (int i = n - 1; i >= 0; --i)
    {
        if (ar[i] % (i + 2) != 0)
        {
            ar.erase(ar.begin() + i);
            i = sz(ar);
        }
    }
    if (ar.empty())
        printf("YES\n");
    else
        printf("NO\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    For(i, t)
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}