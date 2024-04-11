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

const int N = (int) 2e5 + 100;
vector <int> g[N];
long long answer = 0;

struct Ans
{
    int cnt[2];
    long long sum[2];

    Ans() : cnt(), sum() {}


    Ans up() 
    {
        Ans ans = Ans();
        ans.cnt[0] = cnt[1];
        ans.cnt[1] = cnt[0];
        ans.sum[0] = sum[1] + cnt[1];
        ans.sum[1] = sum[0] + cnt[0];
        return ans;
    }

    void sadd(Ans &A)
    {
        cnt[0] += A.cnt[0];
        cnt[1] += A.cnt[1];
        sum[0] += A.sum[0];
        sum[1] += A.sum[1];
    }

    long long calc(Ans &A)
    {
        long long ans = 0;
        for (int t = 0; t < 2; t++)
            for (int at = 0; at < 2; at++)
            {
                long long x = sum[t] * A.cnt[at] + cnt[t] * A.sum[at];
                if ((t + at) % 2)
                    x += cnt[t] * 1LL * A.cnt[at];
                x /= 2;
                ans += x;
            }
        return ans;
    }
};

Ans dfs(int v, int p)
{
    Ans cur = Ans();
    cur.cnt[0] = 1;

    for (int to : g[v])
    {
        if (to == p) continue;
        Ans nx = dfs(to, v);
        answer += cur.calc(nx);
        cur.sadd(nx);
    }

    return cur.up();
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0, 0);
    printf("%lld\n", answer);

	return 0;
}