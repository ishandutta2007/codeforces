#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#endif

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = (int) 1e6 + 100;
char s[N], a[N], b[N];
const int ALP = 30;
int to[ALP];
bool used[ALP];

bool solve(int i, int n, int k, int mask)
{
    if (i == n || mask == 0)
        return true;
    int cur = s[i];
    for (int c = 0; c < k; c++)
    {
        int nmask = mask;
        if (c != to[cur] && to[cur] != -1)
            continue;
        if (used[c] && to[cur] == -1)
            continue;
        if (c < a[i] && (mask & 1))
            continue;
        if (c > b[i] && (mask & 2))
            continue;
        if (c > a[i])
            nmask &= 2;
        if (c < b[i])
            nmask &= 1;
        int pto = to[cur];
        to[cur] = c;
        //eprintf("%d -> %d\n", cur, c);
        used[c] = true;
        if (solve(i + 1, n, k, nmask))
            return true;
        to[cur] = pto;
        if (pto == -1)
            used[c] = false;
    }
    return false;
}

void printTo(int k)
{
    set <int> xs;
    for (int i = 0; i < k; i++)
        if (!used[i])
            xs.insert(i);

    for (int i = 0; i < k; i++)
    {
        if (to[i] != -1) continue;
        to[i] = *xs.begin();
        xs.erase(to[i]);
    }
    for (int i = 0; i < k; i++)
        printf("%c", to[i] + 'a');
    printf("\n");
}

void solve()
{
    int k;
    scanf("%d%s%s%s", &k, s, a, b);
    int n = strlen(s);
    memset(to, -1, sizeof to);
    memset(used, false, sizeof used);
    for (int i = 0; i < n; i++)
    {
        s[i] -= 'a';
        a[i] -= 'a';
        b[i] -= 'a';
    }
    if (solve(0, n, k, 3))
    {
        printf("YES\n");
        printTo(k);
    }
    else
        printf("NO\n");
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve();

	return 0;
}