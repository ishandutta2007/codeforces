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

char s[1000001];
int pi[1000001];
bool yes1[1000001];
bool yes2[1000001];
mt19937 rng(42);

bool comp(int i1, int i2, int len)
{
    For(i, len)
        if (s[i1 + i] != s[i2 + i])
            return false;
    return true;
}

#ifdef LOCAL
#define STRESS
#endif

void solve()
{
#ifdef STRESS
    int n = 10;
    For(i, n)
        s[i] = rng() % 2 + 'a';
    int s_res = 0;
    for (int i = 1; i < n; ++i)
        if (comp(0, n - i, i))
            for (int j = 1; i + j < n; ++j)
                if (comp(0, j, i))
                    s_res = i;
    pi[0] = 0;
    fill(yes1, yes1 + n + 1, false);
    fill(yes2, yes2 + n + 1, false);
#else
    scanf("%s", s);
    int n = strlen(s);
#endif
    for (int i = 1; i < n; ++i)
    {
        pi[i] = pi[i - 1];
        while (pi[i] > 0 && s[pi[i]] != s[i])
            pi[i] = pi[pi[i] - 1];
        if (s[pi[i]] == s[i])
            ++pi[i];
    }
    for (int i = n - 1; i >= 0; --i)
    {
        if (pi[i] && i != n - 1)
            yes1[pi[i] - 1] = true;
    }
    for (int i = pi[n - 1]; i > 0; i = pi[i - 1])
        yes2[i - 1] = true;
#ifdef STRESS
    int my_res = 0;
    for (int i = n - 1; i >= 0; --i)
        if (yes1[i] && yes2[i])
        {
            my_res = i + 1;
            break;
        }
    if (my_res != s_res)
        printf("%s\n", s);
#else
    for (int i = n - 1; i >= 0; --i)
        if (yes1[i] && yes2[i])
        {
            s[i + 1] = 0;
            printf("%s\n", s);
            return;
        }
    printf("Just a legend");
#endif
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef STRESS
    For(_, 10000)
#endif
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}