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


const int LEN = 70;
const int B = 11;

long long dp[LEN][B][B], dpA[LEN][B];

void init()
{
    for (int i = 2; i < B; i++)
        dp[0][i][0] = 1;
    for (int len = 1; len < LEN; len++)
        for (int b = 2; b < B; b++)
            for (int k = 0; k <= b; k++)
            {
                if (k < b) dp[len][b][k] += (b - k) * dp[len - 1][b][k + 1];
                if (k > 0) dp[len][b][k] += k * dp[len - 1][b][k - 1];
            }
    
//    int X = 3;
//    for (int len = 0; len <= 5; len++)
//    {
//        for (int i = 0; i <= 3; i++)
//            eprintf("%lld ", dp[len][X][i] );
//        eprintf("\n");
//    }
    for (int len = 1; len < LEN; len++)
        for (int b = 2; b < B; b++)
        {
//            eprintf("len = %d, b = %d\n", len, b);
//            if (dp[len][b][0] % b != 0) throw;
            dpA[len][b] = dp[len][b][0] - dp[len][b][0] / b;
        }

}


int cnt[B];
int cntOdd;

void cntXOR(int i)
{
    cnt[i] ^= 1;
    if (cnt[i] ) cntOdd++;
    else cntOdd--;
}

long long solve(int b, long long r)
{
    if (r == 0) return 0;

    vector <int> v;
    while (r)
    {
        v.push_back(r % b);
        r /= b;
    }
    reverse(v.begin(), v.end() );

    for (int i = 0; i < B; i++)
        if (cnt[i] )
            cntXOR(i);

 //   for (int x : v)
 //       eprintf("%d ", x);
 //   eprintf(" << \n");

    long long ans = 0;
    int n = (int) v.size();
    for (int i = 0; i < n; i++)
    {
        int cur = v[i];
        for (int j = 0; j < cur; j++)
        {
            if (i == 0 && j == 0) continue;

            cntXOR(j);
    
            ans += dp[n - i - 1][b][cntOdd];

            cntXOR(j);
        }

        if (i != 0)
        {
            ans += dpA[n - i][b];
        }

        cntXOR(cur);
    }

    if (cntOdd == 0)
        ans++;

 //   eprintf("ans = %lld\n", ans);
    return ans;
}

void solve()
{
    int b;
    long long l, r;
    scanf("%d%lld%lld", &b, &l, &r);
    long long ans = solve(b, r) - solve(b, l - 1);
    printf("%lld\n", ans);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    init();

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
        solve();

	return 0;
}