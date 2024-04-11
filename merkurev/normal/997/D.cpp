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

const int MOD = 998244353;
const long long BOUND = MOD * 1LL * MOD * 6;
void sadd(int &a, int b)
{
    a += b;
    if (a >= MOD) a -= MOD;
}
int add(int a, int b)
{
    sadd(a, b);
    return a;
}
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}
void takeMod(long long &a)
{
    if (a >= BOUND)
        a -= BOUND;
}

const int N = 4005;
int n[2], k;

int dp[2][N];
int esz;
int e[2 * N][2];

const int K = 80;
long long cnt[2][K];
int C[K][K];

void init()
{
    for (int i = 0; i < K; i++)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
    }
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    init();

    scanf("%d%d%d", &n[0], &n[1], &k);
    for (int id = 0; id < 2; id++)
    {
        esz = 0;
        for (int i = 0; i < n[id] - 1; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            a--;
            b--;
            e[esz][0] = a;
            e[esz][1] = b;
            esz++;
        }
        for (int s = 0; s < n[id]; s++)
        {
            int t = 0, nt = 1;
            memset(dp, 0, sizeof dp);
            dp[t][s] = 1;
            for (int i = 0; i <= k / 2; i++)
            {
                for (int j = 0; j < n[id]; j++)
                {
                    cnt[id][i * 2] += dp[t][j] * 1LL * dp[t][j];
                    takeMod(cnt[id][i * 2] );
                }
                if (i + 1 > k / 2) continue;

                memset(dp[nt], 0, sizeof dp[nt]);
                for (int j = 0; j < esz; j++)
                {
                    int a = e[j][0], b = e[j][1];
                    sadd(dp[nt][a], dp[t][b]);
                    sadd(dp[nt][b], dp[t][a]);
                }
                swap(t, nt);
           }
        }
        for (int i = 0; i <= k; i++)
        {
            cnt[id][i] %= MOD;
            eprintf("%lld ", cnt[id][i] );
        }
        eprintf("\n");
    }
    int ans = 0;
    for (int a = 0; a <= k; a += 2)
    {
        int cur = mul(C[k][a], mul(cnt[0][a], cnt[1][k - a]));
        sadd(ans, cur);
    }
    
    printf("%d\n", ans);
	return 0;
}