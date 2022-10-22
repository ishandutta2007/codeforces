#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 400005;
const int Maxm = 20;
const ll Inf = 4000000000000000000ll;

int S[Maxn];
int n;
int a[Maxn];
vector <int> my[Maxm];
vector <ii> seq;
ll cost[Maxm][Maxm];
ll dp[1 << Maxm];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]); a[i]--;
        my[a[i]].push_back(i);
    }
    for (int i = 0; i < Maxm; i++) if (my[i].size() > 0)
        seq.push_back(ii(int(my[i].size()), i));
    sort(seq.rbegin(), seq.rend());
    for (int i = 0; i < seq.size(); i++) {
        fill(S, S + n + 1, 0);
        int a = seq[i].second;
        for (int j = 0; j < my[a].size(); j++)
            S[my[a][j]]++;
        for (int j = 1; j <= n; j++)
            S[j] += S[j - 1];
        for (int j = i + 1; j < seq.size(); j++) {
            int b = seq[j].second;
            ll w1 = 0, w2 = 0;
            for (int k = 0; k < my[b].size(); k++) {
                w1 += S[my[b][k]];
                w2 += S[n] - S[my[b][k]];
            }
            cost[a][b] = w2;
            cost[b][a] = w1;
        }
    }
    fill(dp, dp + (1 << Maxm), Inf);
    dp[0] = 0;
    for (int i = 0; i < 1 << Maxm; i++)
        for (int j = 0; j < Maxm; j++) if (!(i & 1 << j)) {
            ll cand = dp[i];
            for (int k = 0; k < Maxm; k++) if (i & 1 << k)
                cand += cost[k][j];
            dp[i | 1 << j] = min(dp[i | 1 << j], cand);
        }
    cout << dp[(1 << Maxm) - 1] << endl;
    return 0;
}