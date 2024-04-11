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


const int LEN = (int) 2e5 + 100;
char str[LEN];

int nx0[LEN];
int cnt[LEN][2];
int xxx[LEN];

const int K = 32;
unsigned bs[K][LEN / K];


bool cmpEq(int a, int b, int len)
{
  //  eprintf("cmp %d %d %d\n", a, b, len);
    int sha = a % K, shb = b % K;
    int sa = a / K, sb = b / K;
    int full = len / K;
    unsigned ans = 0U;
    for (int i = 0; i < full; i++)
        ans |= bs[sha][sa + i] ^ bs[shb][sb + i];
    int rem = len % K;
  //  eprintf("rem = %d\n", rem);
  //  eprintf("%d %d ^ %d %d\n", sha, sa + full, shb, sb + full);
  //  eprintf("%u ^ %u & %u\n", bs[sha][sa + full], bs[shb][sb + full], (1U << rem) - 1U);
    //eprintf("ans = %u\n", ans);
    ans |= (bs[sha][sa + full] ^ bs[shb][sb + full]) & ((1U << rem) - 1U);
    //eprintf("ans = %u\n", ans);
    return ans == 0U;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    scanf("%s", str);

    nx0[n] = n;
    for (int i = n - 1; i >= 0; i--)
    {
        nx0[i] = nx0[i + 1];
        if (str[i] == '0')
            nx0[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cnt[i + 1][0] = cnt[i][0] + (str[i] == '0');
        cnt[i + 1][1] = cnt[i][1] + (str[i] == '1');
    }

    int prv = 0;
    for (int i = 0; i < n; i++)
        if (str[i] == '0')
        {
            int cur = cnt[i][1];
            if (cur % 2 != prv % 2)
                xxx[cnt[i][0]] = 1;
            prv = cur;
        }

    int m = cnt[n][0];
   // for (int i = 0; i < m; i++)
   //     eprintf("%d", xxx[i]); eprintf("\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < K; j++)
        {
            int sh = i - j;
            if (sh < 0)
                continue;
    //        eprintf("%d %d |= %d << %d\n", j, sh / K, xxx[i], sh % K);
            bs[j][sh / K] |= ((unsigned)xxx[i] << (sh % K));
        }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int a, b, len;
        scanf("%d%d%d", &a, &b, &len);
        a--;
        b--;
        int sa = cnt[a][0], sb = cnt[b][0];
        int ea = cnt[a + len][0], eb = cnt[b + len][0];
        if (ea - sa != eb - sb)
        {
            eprintf("diff number of 0s: %d vs %d\n", ea - sa, eb - sb);
            printf("No\n");
            continue;
        }
        if (ea - sa != 0)
        {
            //eprintf("check oddity of leading 1s: %d vs %d\n", nx0[a] - a, nx0[b] - b);
            if ((nx0[a] - a) % 2 != (nx0[b] - b) % 2)
            {
    //            eprintf("diff oddity of leading 1s: %d vs %d\n", nx0[a] - a, nx0[b] - b);
                printf("No\n");
                continue;
            }
            if (!cmpEq(sa + 1, sb + 1, ea - sa - 1))
            {
                printf("No\n");
                continue;
            }
        }
        printf("Yes\n");
    }


	return 0;
}