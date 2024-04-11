#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxm = 205;
const ll Inf = 1000000000000000000ll;

int n, m, k;
int S[Maxn], T[Maxn], D[Maxn], W[Maxn];
int seq[Maxn];
set <int> St;
int my[Maxn];
ll dp[Maxn][Maxm];

bool Less(const int &a, const int &b)
{
    if (W[a] != W[b]) return W[a] > W[b];
    return D[a] > D[b];
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d %d", &S[i], &T[i], &D[i], &W[i]);
        seq[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        St.insert(i);
        my[i] = -1;
    }
    sort(seq, seq + k, Less);
    for (int z = 0; z < k; z++) {
        int i = seq[z];
        set <int>::iterator lef = St.lower_bound(S[i]);
        set <int>::iterator rig = St.upper_bound(T[i]);
        while (lef != rig) {
            my[*lef] = i;
            St.erase(lef++);
        }
    }
    for (int j = 0; j <= m; j++)
        dp[n + 1][j] = 0;
    for (int i = n; i > 0; i--)
        for (int j = 0; j <= m; j++)
            if (my[i] == -1) dp[i][j] = dp[i + 1][j];
            else {
                dp[i][j] = Inf;
                if (j < m) dp[i][j] = min(dp[i][j], dp[i + 1][j + 1]);
                dp[i][j] = min(dp[i][j], ll(W[my[i]]) + dp[D[my[i]] + 1][j]);
            }
    cout << dp[1][0] << endl;
    return 0;
}