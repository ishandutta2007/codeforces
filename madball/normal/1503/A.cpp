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

bool check(char* s)
{
    int bal = 0;
    while (*s)
    {
        bal += *s == '(' ? 1 : -1;
        if (bal < 0)
            return false;
        ++s;
    }
    return bal == 0;
}

void solve()
{
    int n;
    scanf("%d", &n);
    static char s[(int)2e5 + 10];
    scanf(" %s", &s);
    static char a[(int)2e5 + 10];
    static char b[(int)2e5 + 10];
    a[n] = b[n] = 0;
    int cnt = 0;
    For(i, n)
        cnt += s[i] == '1';
    if (cnt % 2)
    {
        printf("NO\n");
        return;
    }
    int cnt2 = 0;
    bool kek = false;
    For(i, n)
    {
        if (s[i] == '1')
        {
            if (cnt2 * 2 < cnt)
                a[i] = b[i] = '(';
            else
                a[i] = b[i] = ')';
            ++cnt2;
        }
        else
        {
            if (kek)
            {
                a[i] = '(';
                b[i] = ')';
            }
            else
            {
                b[i] = '(';
                a[i] = ')';
            }
            kek = !kek;
        }
    }
    if (check(a) && check(b))
        printf("YES\n%s\n%s\n", a, b);
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