#ifndef LOCAL
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
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
#include <queue>
#include <random>
#include <ctime>
#include <chrono>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif


typedef long long int int64;
typedef long long int ll;
typedef long long unsigned ull;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

const int N = (int) 2e5 + 100;
char s[N];
int bal[N];


void solve()
{
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < 2 * n; i++)
        bal[i + 1] = bal[i] + (s[i] == '(' ? 1 : -1);
    int f_mx = 0, l_mx = 0;
    for (int i = 0; i <= 2 * n; i++)
        if (bal[i] > bal[f_mx])
        {
            f_mx = l_mx = i;
        }
        else if (bal[i] == bal[f_mx])
        {
            l_mx = i;
        }
    int fneg = -1, lneg = -1;
    for (int i = 0; i < 2 * n; i++)
        if (bal[i] < 0)
        {
            lneg = i;
            if (fneg == -1)
                fneg = i;
        }
    if (fneg == -1)
    {
        printf("0\n");
        return;
    }

    int fmx = 0;
    int lmx = 2 * n;
    for (int i = 0; i < 2 * n; i++)
    {
        if (i < fneg && bal[i] > bal[fmx])
            fmx = i;
        if (i > lneg && bal[i] > bal[lmx])
            lmx = i;
    }
    reverse(s + fmx, s + lmx);
    //eprintf("%d %d : %s\n", fmx, lmx, s);
    int cb = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (s[i] == '(')
            cb++;
        else
            cb--;
        if (cb < 0)
            cb -= 3 * n;
    }
    if (cb == 0)
    {
        printf("1\n%d %d\n", fmx + 1, lmx);
        return;
    }

    printf("2\n%d %d\n%d %d\n", 1, f_mx, f_mx + 1, 2 * n);
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