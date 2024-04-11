#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;
typedef long long ll;

const int mod = 1000000007;
const int Maxn = 1005;
const int Maxd = 4;

int n, p;
deque <iii> A, B;
int has[Maxd];
int dp[Maxn][Maxd];

void Add(deque <iii> &V, const iii &p)
{
    if (!V.empty() && V.back().second == p.second) V.back().first.second = max(V.back().first.second, p.first.second);
    else V.push_back(p);
}

void Add(int l, int r, int val)
{
    has[val] = (has[val] + (ll(p - l) + ll(p - r)) * (r - l + 1) / 2) % mod;
    ll lef = max(ll(r) + 1, 3 * ll(l)), rig = min(ll(p) - 1, 3 * ll(r) + 2ll);
    if (lef <= rig) Add(A, iii(ii(lef, rig), val));
    lef = max(ll(r) + 1, ll(l) + (l - 1) / 2), rig = min(ll(p) - 1, ll(r) + r / 2);
    if (lef <= rig) Add(B, iii(ii(lef, rig), val));
}

int main()
{
    scanf("%d %d", &n, &p);
    if (p == 1) { printf("0\n"); return 0; }
    int l = 1, r = min(2, p - 1);
    Add(l, r, 0);
    while (!A.empty() && !B.empty())
        if (!A.empty() && A.front().first.second <= r) A.pop_front();
        else if (!B.empty() && B.front().first.second <= r) B.pop_front();
        else {
            int nl = r + 1, nr = min(A.front().first.second, B.front().first.second);
            int cur = 0;
            while (cur == A.front().second || cur == B.front().second) cur++;
            l = nl; r = nr;
            Add(l, r, cur);
        }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < Maxd; j++) if (dp[i][j])
            for (int l = 0; l < Maxd; l++)
                dp[i + 1][j ^ l] = (dp[i + 1][j ^ l] + ll(dp[i][j]) * has[l]) % mod;
    int res = 0;
    for (int j = 1; j < Maxd; j++)
        res = (res + dp[n][j]) % mod;
    printf("%d\n", res);
    return 0;
}