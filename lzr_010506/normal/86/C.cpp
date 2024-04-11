#include <bits/stdc++.h>
#define N 15
using namespace std;

const int mod = 1000000009;
int dp[1010][110][N], l[N], c[3000010];
char s[N];

int get(char c)
{
    if(c == 'A') return 0;
    if(c == 'C') return 1;
    if(c == 'G') return 2;
    return 3;
}

struct ac_auto
{
    queue<int> Q;
    int tot, c[4][110];
    int val[110] , fail[110];

    int new_node ()
    {
        for(int i = 0; i < 4; i ++) c[i][tot] = 0;
        fail[tot] = val[tot] = 0;
        return tot ++;
    }

    void init ()
    {
        tot = 0;
        new_node ();
    }

    void insert(char *s , int id)
    {
        int now = 0;
        for(; *s; s ++)
        {
            int k = get(*s);
            if(!c[k][now]) c[k][now] = new_node ();
            now = c[k][now];
        }
        val[now] = max(val[now] , l[id]);
    }

    void get_fail ()
    {
        int u = 0;
        for(int i = 0; i < 4; i ++)
            if(c[i][u])
                Q.push(c[i][u]);
        while(!Q.empty ())
        {
            u = Q.front ();
            Q.pop ();
            for(int i = 0; i < 4; i ++)
                if(c[i][u])
                {
                    int e = c[i][u];
                    int j = fail[u];
                    fail[e] = c[i][j];
                    val[e] = max(val[e] , val[fail[e]]);
                    Q.push(e);
                }
                else c[i][u] = c[i][fail[u]];
        }
    }

    void solve(int n)
    {
        for(int i = 1; i <= n; i ++)
            for(int j = 0; j < tot; j ++)
                for(int k = 0; k <= 10; k ++)
                    if(dp[i - 1][j][k])
                        for(int p = 0; p < 4; p ++)
                            if(val[ c[p][j] ] >= k + 1) dp[i][ c[p][j] ][0] = (dp[i][ c[p][j] ][0] + dp[i - 1][j][k]) % mod;
                            else dp[i][ c[p][j] ][k + 1] = (dp[i][ c[p][j] ][k + 1] + dp[i - 1][j][k]) % mod;
    }

} ac;
int main ()
{
    int n, m, j;
    scanf("%d%d" , &n , &m);
    ac.init ();
    j = 0;
    while(m --)
    {
        scanf("%s" , s);
        l[++ j] = strlen(s);
        ac.insert(s , j);
    }
    ac.get_fail();
    memset(dp , 0 , sizeof(dp));
    dp[0][0][0] = 1;
    ac.solve(n);
    int ans = 0;
    for(int i = 0; i < ac.tot; i ++)
        ans =(ans + dp[n][i][0]) % mod;
    printf("%d\n", ans);
    return 0;
}