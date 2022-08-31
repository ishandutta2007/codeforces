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
char str[N];
char a[N], b[N];

void solve()
{
    int n;
    scanf("%d", &n);
    scanf("%s", str);

    int ba = 0, bb = 0;
    int cnt1 = 0;
    for (int i = 0; i < n; i++)
        if (str[i] == '1')
            cnt1++;
    if (cnt1 % 2)
    {
        printf("NO\n");
        return;
    }
    int k11 = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0')
        {
            if (ba == 0 && bb == 0)
            {
                printf("NO\n");
                return;
            }
            if (ba > bb)
            {
                a[i] = ')';
                b[i] = '(';
                ba--;
                bb++;
            }
            else
            {
                a[i] = '(';
                b[i] = ')';
                ba++;
                bb--;
            }
        }
        else if (str[i] == '1')
        {
            if (k11 * 2 < cnt1)
            {
                a[i] = '(';
                b[i] = '(';
                k11++;
                ba++;
                bb++;
            }
            else
            {
                if (ba == 0 || bb == 0)
                {
                    printf("NO\n");
                    return;
                }
                a[i] = ')';
                b[i] = ')';
                ba--;
                bb--;
            }
        }
    }
    printf("YES\n");
    a[n] = 0;
    b[n] = 0;
    printf("%s\n%s\n", a, b);
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