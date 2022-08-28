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


const int N = (int) 5e5 + 100;
vector <int> g[N];



int takeNew = 0;

struct Dp
{
    long long val[2][3][2];

    Dp() : val() {}

    Dp operator + (const Dp &A) const
    {
        Dp ans = Dp();

        for (int full = 0; full <= 1; full++)
            for (int fullA = 0; fullA <= 1; fullA++)
            {
                if (full && !fullA) continue;
                int fullN = (full || !fullA);

                for (int numv = 0; numv <= 2; numv++)
                    for (int numvA = 0; numvA <= 2; numvA++)
                    {
                        if (numv + numvA > 2) continue;
                        int numvN = numv + numvA;

                        for (int delEdge = 0; delEdge <= 1; delEdge++)
                            for (int delEdgeA = 0; delEdgeA <= 1; delEdgeA++)
                            {
                                if (delEdge + delEdgeA > 1) continue;

                                long long cnt = val[full][numv][delEdge];
                                long long cntA = A.val[fullA][numvA][delEdgeA];
                            
                                long long cntN = cnt * cntA;
                                if (cntN == 0) continue;

                                for (int delCur = 0; delCur <= 1; delCur++)
                                {
                                    int delEdgeN = delEdge + delEdgeA + delCur;
                                    if (delEdgeN > 1) continue;
                                    if (delCur && numvA != 1) continue;
                                    if (delCur && fullA != 1) continue;
                                    
                                    ans.val[fullN][numvN][delEdgeN] += cntN;
                                }
                            }
                    }
            }

        return ans;
    }

    Dp up() const
    {
        Dp ans = Dp();
        
        for (int full = 0; full <= 1; full++)
            for (int numv = 0; numv <= 2; numv++)
                for (int delEdge = 0; delEdge <= 1; delEdge++)
                {
                    long long cur = val[full][numv][delEdge];
                    if (cur == 0) continue;
                    ans.val[full][numv][delEdge] += cur;
                    
                    if (takeNew)
                    {
                        if (full == 0)
                        {
                            if (numv == 0)
                                ans.val[1][1][0] += cur;
                            if (numv == 1 && delEdge == 1)
                                ans.val[1][2][1] += cur;
                        }
                    }
                    else
                    {
                        if (full == 0)
                        {
                            if (numv == 0)
                                ans.val[0][1][0] += cur;
                            if (numv == 1 && delEdge == 1)
                                ans.val[0][2][1] += cur;
                        }
                        else 
                        {
                            if (numv == 0)
                                ans.val[1][1][0] += cur;
                            else if (numv == 1 && delEdge == 1)
                                ans.val[1][2][1] += cur;
                        }
                    }
                }

        return ans;
    }


    void eprint(int v)
    {
        eprintf("v = %d\n", v);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                for (int h = 0; h < 2; h++)
                    eprintf("curv matched = %d, cntChoosed = %d, edgeDeleted = %d : %lld\n", i, j, h, val[i][j][h] );
        
    }
};

Dp dp[N];

void dfs(int v, int par)
{
    dp[v] = Dp();
    dp[v].val[0][0][0] = 1;

    for (int to : g[v] )
    {
        if (to == par) continue;
        dfs(to, v);

//        eprintf("%d -> %d\n", v, to);
        dp[v] = dp[v] + dp[to];
//        dp[v].eprint(v);
    }

    dp[v] = dp[v].up();
//    dp[v].eprint(v);
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


    long long ans = 0;
    dfs(0, 0);

    ans += dp[0].val[1][2][1];

    takeNew = 1;
    eprintf("\n\n\n");
    dfs(0, 0);

    ans += dp[0].val[1][2][1];


    printf("%lld\n", ans);

	return 0;
}