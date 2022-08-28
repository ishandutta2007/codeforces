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

const int MOD = (int) 1e9 + 7;
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
void ssub(int &a, int b)
{
    a -= b;
    if (a < 0) a += MOD;
}
int sub(int a, int b)
{
    ssub(a, b);
    return a;
}
int mul(long long a, long long b)
{
    return (a * 1LL * b) % MOD;
}
int fpow(int x, int n)
{
    if (n == 0) return 1;
    int a = fpow(x, n >> 1);
    a = mul(a, a);
    if (n & 1) a = mul(a, x);
    return a;
}
int rev(int x)
{
    return fpow(x, MOD - 2);
}
int divi(int a, int b)
{
    return mul(a, rev(b));
}

const int D = 70;
const int K = (int) 1e4 + 100;
int dp[K][D];
int ri[K];

void init()
{
    ri[1] = 1;
    for (int i = 2; i < K; i++)
    {
        ri[i] = sub(0, mul(MOD / i, ri[MOD % i]));
        //if (mul(i, ri[i]) != 1) throw;
    }
}

vector <int> getProbs(int deg, int k)
{
    memset(dp, 0, sizeof dp);
    dp[0][deg] = 1;
    for (int i = 0; i < k; i++)
        for (int j = 0; j <= deg; j++)
        {
            int x = mul(dp[i][j], ri[j + 1]);
            for (int h = 0; h <= j; h++)
                sadd(dp[i + 1][h], x);
        }
    vector <int> ans;
    for (int i = 0; i <= deg; i++)
        ans.push_back(dp[k][i]);
    return ans;
}

int answer;

void genAnswer(int pos, int prob, int val, vector <pair<long long, int>> &ps, vector <vector <int>> &prs)
{
    if (pos == (int) ps.size())
    {
        int cur = mul(prob, val);
        eprintf("prob = %d, val = %d\n", prob, val);
        sadd(answer, cur);
        return;
    }
    int nx = val;
    for (int i = 0; i <= ps[pos].second; i++)
    {
        int nprob = mul(prob, prs[pos][i]);
        genAnswer(pos + 1, nprob, nx, ps, prs);
        nx = mul(nx, ps[pos].first);
    }
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    init();

    long long n;
    int k;
    
    scanf("%lld%d", &n, &k);

    vector <pair <long long, int>> ps;
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i != 0) continue;
        ps.emplace_back(i, 0);
        while (n % i == 0)
        {
            n /= i;
            ps.back().second++;
        }
    }
    if (n != 1)
        ps.emplace_back(n, 1);

    vector <vector <int>> prs;
    for (auto p : ps)
    {
        vector <int> probs = getProbs(p.second, k);
        prs.push_back(probs);
    }

    genAnswer(0, 1, 1, ps, prs);

    printf("%d\n", answer);

	return 0;
}