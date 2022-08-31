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

const int INF = (int) 1e9 + 100;
const int N = (int) 2e5 + 100;
char str[N];
int a[N];

const int SZ = 2 * N;
int val[2 * SZ];
    
set <pair <int, int>> up, down;

void update(int pos, int x)
{
    eprintf("%d <- %d\n", pos, x);
    up.erase({val[pos], pos});
    val[pos] = min(val[pos], x);
    up.insert({val[pos], pos});
}
int dadd;

int getCur()
{
    int ans = INF;
    ans = min(ans, up.begin()->first);
    ans = min(ans, down.begin()->first + dadd);
    eprintf(">> %d %d+%d\n", up.begin()->first, down.begin()->first, dadd);
    return ans;
}

void solve()
{
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    for (int i = 0; i < n; i++)
        a[i] = str[i] - '0';

    int cnt[2] = {0, 0};
    for (int i = 0; i < n; i++)
        cnt[a[i]]++;

    if (cnt[1] > cnt[0])
    {
        reverse(a, a + n);
        for (int i = 0; i < n; i++)
            a[i] ^= 1;
        swap(cnt[0], cnt[1]);
    }

    for (int i = N - n; i <= N + n; i++)
    {
        val[i] = INF;
    }

    up.clear();
    down.clear();
    dadd = 0;
    up.insert({INF, INF});
    down.insert({INF, INF});

    int pos = N;
    int cnt1 = 0;
    int cnt0 = 0;

    update(pos, 0);

    int last = INF;
    for (int i = 0; i < n; i++)
    {
        int cur;
        if (a[i] == 0)
        {
            cnt0++;
            up.erase({val[pos], pos});
            down.insert({val[pos] - dadd, pos});
            dadd++;
            pos++;

            cur = getCur();
            eprintf("cur = %d\n", cur);
            if (cnt1 == 0)
            {
                update(pos, 0);
                last = 0;
            }
            else
            {
                update(pos + cnt1, cur + 1);
                last = cur + 1;
            }
        }
        else
        {
            cnt1++;
            pos--;
            dadd--;
            down.erase({val[pos] - dadd, pos});
            up.insert({val[pos], pos});
           
            cur = getCur();

            update(pos + cnt1, cur + 1);
            last = min(last, cur + 1);
        }
        eprintf("i = %d, last = %d\n", i, last);
    }
    printf("%d\n", last);
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve();

	return 0;
}