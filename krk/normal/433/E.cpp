#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 205;
const int Maxk = 505;
const int mod = 1000000007;
const int sigma = 20;

int term[Maxn], len[Maxn], to[Maxn][sigma], link[Maxn], sz = 1;
ll vals[Maxn];
void add_str(const vector <int> &V, int val)
{
    int cur = 0;
    for(auto c: V)
    {
        if(!to[cur][c])
        {
            to[cur][c] = sz++;
            len[to[cur][c]] = len[cur] + 1;
        }
        cur = to[cur][c];
    }
    term[cur] = cur;
    vals[cur] += val;
}

void push_links()
{
    int que[sz];
    int st = 0, fi = 1;
    que[0] = 0;
    while(st < fi)
    {
        int V = que[st++];
        int U = link[V];
        if(!term[V]) term[V] = term[U];
        for(int c = 0; c < sigma; c++)
            if(to[V][c])
            {
                link[to[V][c]] = V ? to[U][c] : 0;
                if (V) vals[to[V][c]] += vals[to[U][c]];
                que[fi++] = to[V][c];
            }
            else
            {
                to[V][c] = to[U][c];
            }
    }
}

int n, m, K;
vector <int> L;
vector <int> R;
int dp[Maxn][Maxn][Maxk];

vector <int> readNum()
{
    int sz; scanf("%d", &sz);
    vector <int> res(sz);
    for (int i = 0; i < sz; i++)
        scanf("%d", &res[i]);
    return res;
}

int Get(const vector <int> &my, bool inc)
{
    int res = 0;
    for (int i = 1; i < my.size(); i++)
        for (int j = 1; j < m; j++) {
            int nj = to[0][j];
            int nk = vals[nj];
            if (nk <= K) res = (res + dp[i - 1][nj][nk]) % mod;
        }
    int j = 0;
    ll k = 0;
    for (int i = 0; i < my.size() && k <= K; i++) {
        for (int d = (i == 0? 1: 0); d < my[i]; d++) {
            int nj = to[j][d];
            int nk = k + vals[nj];
            if (nk <= K) res = (res + dp[int(my.size()) - 1 - i][nj][nk]) % mod;
        }
        j = to[j][my[i]];
        k += vals[j];
    }
    if (k <= K && inc) res = (res + 1) % mod;
    return res;
}

int main()
{
    scanf("%d %d %d", &n, &m, &K);
    L = readNum();
    R = readNum();
    for (int i = 0; i < n; i++) {
        vector <int> tmp = readNum();
        int val; scanf("%d", &val);
        add_str(tmp, val);
    }
    push_links();
    for (int j = 0; j < sz; j++)
        for (int k = 0; k <= K; k++)
            dp[0][j][k] = 1;
    for (int i = 1; i < Maxn; i++)
        for (int j = 0; j < sz; j++)
            for (int k = 0; k <= K; k++) {
                for (int nxt = 0; nxt < m; nxt++) {
                    int nj = to[j][nxt];
                    ll nk = k + vals[nj];
                    if (nk <= K)
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][nj][nk]) % mod;
                }
            }
    int res = (Get(R, true) - Get(L, false) + mod) % mod;
    printf("%d\n", res);
    return 0;
}