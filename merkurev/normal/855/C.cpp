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
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}


int k, m;
const int N = (int) 1e5 + 100;
const int K = 11;
vector <int> g[N];

struct Ans
{
    int l[K], e[K], g[K];

    Ans() : l(), e(), g() {}

    Ans(bool flag) : l(), e(), g() 
    {
        if (!flag) throw;
        l[0] = k - 1;
        e[1] = 1;
        g[0] = m - k;
    }

    int getAns(int x) const
    {
        int ans = 0;
        for (int i = 0; i <= x; i++)
        {
            sadd(ans, l[i]);
            sadd(ans, e[i]);
            sadd(ans, g[i]);
        }
        return ans;
    }

    Ans operator + (const Ans &A) const
    {
        Ans ans = Ans();

        for (int i = 0; i < K; i++)
            for (int j = 0; i + j < K; j++)
            {
                sadd(ans.e[i + j], mul(e[i], A.l[j] ) );
                
                sadd(ans.l[i + j], mul(l[i], A.l[j] ) );
                sadd(ans.l[i + j], mul(l[i], A.e[j] ) );
                sadd(ans.l[i + j], mul(l[i], A.g[j] ) );
                
                sadd(ans.g[i + j], mul(g[i], A.l[j] ) );
                sadd(ans.g[i + j], mul(g[i], A.g[j] ) );
            }

        return ans;
    }

};

Ans dp[N];

void dfs(int v, int par)
{
    dp[v] = Ans(true);

    for (int to : g[v] )
    {
        if (to == par) continue;
        dfs(to, v);
        dp[v] = dp[v] + dp[to];
    }
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int x;
    scanf("%d%d", &k, &x);
    
    dfs(0, 0);

    int ans = dp[0].getAns(x);
    printf("%d\n", ans);


	return 0;
}