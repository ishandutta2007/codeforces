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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

vector <int> vtest;

void eprintb(int x)
{
    for (int i = 20; i >= 0; i--)
        if (x >> i)
            printf("%d", (x >> i) & 1);
        else
            printf(" ");
    printf("\n");
}

const int N = (int) 1e6 + 100;
bool used[N];

long long zzz[4] = {0, 2, 3, 1};

long long getX(int len, long long pos)
{
    long long ans = (1LL << len);
    for (int i = 0; i < len; i += 2)
    {
        ans |= zzz[(pos >> i) & 3LL] << i;
    }
    return ans;
}

long long solve1(long long pos)
{
    int len = 1;
    while (pos >= 3LL * (1LL << (len - 1)))
    {
        pos -= 3LL * (1LL << (len - 1));
        len += 2;
    }


    int rem = pos % 3;
    pos /= 3;

    long long val = (1LL << (len - 1)) + pos;

    if (rem == 0)
        return val;

    //eprintf("val = %lld\n", val);
    //eprintb(val);
    //eprintf("pos = %lld\n", pos);
    //eprintb(pos);
    long long x = getX(len, pos);
    if (rem == 1)
        return x;
    if (rem == 2)
        return x ^ val;

    throw;
}

void solve()
{
    long long pos;
    scanf("%lld", &pos);
    pos--;

    long long ans = solve1(pos);

    if (ans >= 0 && pos < (int) vtest.size() && vtest[pos] != ans)
    {
        eprintf("%lld : %lld vs (correct %d)\n", pos, ans, vtest[pos]);
        eprintb(pos);
        eprintb(ans);
        eprintb(vtest[pos]);
        throw;
    }

    printf("%lld\n", ans);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    for (int i = 1; i < (int) 100; i++)
    {
        if (used[i])
            continue;
        used[i] = true;
        for (int j = i + 1; j < N; j++)
        {
            int h = i ^ j;
            if (used[j] || used[h])
                continue;
            used[i] = used[j] = used[h] = true;
            //eprintf("i = %d\n", i);
            //eprintb(i);
            //eprintb(j);
            //eprintb(h);
            vtest.push_back(i);
            vtest.push_back(j);
            vtest.push_back(h);
            //eprintf("--\n");
            break;
        }
    }


    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve();
	return 0;
}