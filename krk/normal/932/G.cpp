#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000005, sigma = 26;
const int mod = 1000000007;

char tmp[maxn];
int tlen;
char str[maxn];
int slen;
int s[maxn], len[maxn], link[maxn], to[maxn][sigma];
int n, last, sz;
int dif[maxn], slink[maxn];
int dp[maxn], dpser[maxn][2];
 
void init()
{
    s[n++] = -1;
    link[0] = 1;
    len[1] = -1;
    sz = 2;
}
 
int get_link(int v)
{
    while(s[n - len[v] - 2] != s[n - 1]) v = link[v];
    return v;
}
 
void add_letter(int c)
{
    s[n++] = c;
    last = get_link(last);
    if(!to[last][c])
    {
        len [sz] = len[last] + 2;
        link[sz] = to[get_link(link[last])][c];
        dif[sz] = len[sz] - len[link[sz]];
        slink[sz] = dif[sz] == dif[link[sz]]? slink[link[sz]]: link[sz];
        to[last][c] = sz++;
    }
    last = to[last][c];
}

int main()
{
    scanf("%s", tmp);
    tlen = strlen(tmp);
    int l = 0, r = tlen - 1;
    while (l < r) {
        str[slen++] = tmp[l++];
        str[slen++] = tmp[r--];
    }
    init();
    dp[0] = 1;
    for (int i = 1; i <= slen; i++) {
        add_letter(str[i - 1] - 'a');
        for (int v = last; len[v] > 0; v = slink[v]) {
            int plen = len[slink[v]] + dif[v];
            dpser[v][0] = dpser[v][1] = 0;
            dpser[v][(i - plen) % 2] = dp[i - plen];
            if (dif[v] == dif[link[v]]) {
                dpser[v][0] = (dpser[v][0] + dpser[link[v]][0]) % mod;
                dpser[v][1] = (dpser[v][1] + dpser[link[v]][1]) % mod;
            }
            dp[i] = (dp[i] + dpser[v][i % 2]) % mod;
        }
    }
    printf("%d\n", dp[slen]);
    return 0;
}