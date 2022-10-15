/**
 * @author Macesuted
 * @date 2021-01-07
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define bufferSiz (1 << 18)
char Buff[bufferSiz], *_S = Buff, *_T = Buff;
#define getchar() (_S == _T && (_T = (_S = Buff) + fread(Buff, 1, bufferSiz, stdin), _S == _T) ? EOF : *_S++)

template <typename T>
T read(void) {
    T f = 1, num = 0;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')
            f = -f;
        c = getchar();
    }
    while (isdigit(c)) {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return f * num;
}

#define mod 1000000007
#define maxn 100005
#define maxk 205

vector<int> graph[maxn];
int S[maxk][maxk], f[maxn], dp[maxn][maxk], ans[maxk];
int siz[maxn];
int n, k;

inline int Mod(int x) { return x >= mod ? x - mod : x; }

void dfs(int p, int fa) {
    siz[p] = 1, dp[p][0] = 2;
    for (vector<int>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
        if (*i != fa) {
            dfs(*i, p);
            for (int x = 0; x <= k; x++) f[x] = 0;
            for (int x = 0, lim = min(siz[p], k); x <= lim; x++)
                for (int y = 0, lim2 = min(siz[*i], k - x); y <= lim2; y++)
                    f[x + y] = Mod(f[x + y] + 1LL * dp[p][x] * dp[*i][y] % mod);
            for (int x = 0; x <= k; x++) dp[p][x] = f[x], ans[x] = Mod(ans[x] - dp[*i][x] + mod);
            siz[p] += siz[*i];
        }
    for (int i = 0; i <= k; i++) ans[i] = Mod(ans[i] + dp[p][i]);
    for (int i = k; i; i--) dp[p][i] = Mod(dp[p][i] + dp[p][i - 1]);
    dp[p][1]--;
    return;
}

int main() {
    n = read<int>(), k = read<int>();
    for (int i = 1, from, to; i < n; i++) from = read<int>(), to = read<int>(), graph[from].push_back(to), graph[to].push_back(from);
    S[1][1] = 1;
    for (int i = 2; i <= k; i++)
        for (int j = 1; j <= i; j++)
            S[i][j] = Mod(S[i - 1][j - 1] + 1LL * S[i - 1][j] * j % mod);
    dfs(1, -1);
    long long answer = 0, fac = 1;
    for (int i = 0; i <= k; i++, fac = fac * i % mod) answer = Mod(answer + fac * S[k][i] % mod * ans[i] % mod);
    printf("%lld\n", answer);
    return 0;
}