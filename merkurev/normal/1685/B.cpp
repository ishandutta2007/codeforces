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

void solve()
{
    int a, b, ab, ba;
    scanf("%d%d%d%d", &a, &b, &ab, &ba);
    scanf("%s", s);
    int n = strlen(s);

    int sa = 0, sb = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
            sa++;
        else
            sb++;
    }
    if (a + ab + ba != sa || b + ab + ba != sb)
    {
        printf("NO\n");
        return;
    }
    vector <int> axa, axb, bxa, bxb;

    s[n] = s[n - 1];
    for (int i = 0; i < n; i++)
    {
        int r = i;
        while (s[r + 1] != s[r])
            r++;
        int len = r - i + 1;
       
        if (r > i)
        {
            if (s[i] == 'A')
            {
                if (s[r] == 'A')
                    axa.push_back(len);
                else
                    axb.push_back(len);
            }
            else
            {
                if (s[r] == 'A')
                    bxa.push_back(len);
                else
                    bxb.push_back(len);
            }
        }

        i = r;
    }
    sort(axa.begin(), axa.end());
    sort(bxb.begin(), bxb.end());
    sort(axb.begin(), axb.end());
    sort(bxa.begin(), bxa.end());

    int sx = 0;
    for (int len : axa)
        sx += len / 2;
    for (int len : bxb)
        sx += len / 2;

    int sab = 0;
    for (int len : axb)
        sab += len / 2;
    int sba = 0;
    for (int len : bxa)
        sba += len / 2;

    while (sab + sx < ab)
    {
        if (bxa.empty())
        {
            printf("NO\n");
            return;
        }
        sba -= bxa.back() / 2;
        sx += bxa.back() / 2 - 1;
        bxa.pop_back();
    }
    while (sba + sx < ba)
    {
        if (axb.empty())
        {
            printf("NO\n");
            return;
        }
        sab -= axb.back() / 2;
        sx += axb.back() / 2 - 1;
        axb.pop_back();
    }
    if (sab + sx < ab || sba + sx < ba || sab + sba + sx < ab + ba)
    {
        printf("NO\n");
        return;
    }
    printf("YES\n");

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