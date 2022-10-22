#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1005;
const int Maxm = 1000005;
const int mod = 998244353;

int n, m;
int P[Maxm];
int realR[Maxm], realL[Maxm];
int myR[Maxn], myL[Maxn];
vector <int> S;
vector <int> my[Maxn];
vector <int> un;
int L[Maxn], R[Maxn];
int mn[Maxn][Maxn];
int dp[Maxn][Maxn];
int badlef[Maxn][Maxn];
int badrig[Maxn][Maxn];
bool bad[Maxn][Maxn];

int Get(int l, int r)
{
    return l <= r? dp[l][r]: 1;
}

bool Bad(int l, int r) { return l > r? false: bad[l][r]; }

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &P[i]);
        my[P[i]].push_back(i);
    }
    for (int i = m - 1; i >= 0; i--) {
        while (!S.empty() && P[i] <= P[S.back()])
            S.pop_back();
        if (!S.empty()) realR[i] = S.back() - 1;
        else realR[i] = m - 1;
        S.push_back(i);
    }
    S.clear();
    for (int i = 0; i < m; i++) {
        while (!S.empty() && P[i] <= P[S.back()])
            S.pop_back();
        if (!S.empty()) realL[i] = S.back() + 1;
        else realL[i] = 0;
        S.push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        un.push_back(my[i][0]);
        un.push_back(my[i].back());
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    for (int i = 0; i < un.size(); i++)
        for (int j = i; j < un.size(); j++)
            mn[i][j] = Maxn;
    for (int i = 1; i <= n; i++) {
        L[i] = my[i][0];
        R[i] = my[i].back();
        if (realR[L[i]] < R[i] || L[i] < realL[R[i]]) { printf("0\n"); return 0; }
        myR[i] = upper_bound(un.begin(), un.end(), realR[R[i]]) - un.begin() - 1;
        myL[i] = lower_bound(un.begin(), un.end(), realL[L[i]]) - un.begin();
        L[i] = lower_bound(un.begin(), un.end(), L[i]) - un.begin();
        R[i] = lower_bound(un.begin(), un.end(), R[i]) - un.begin();
        mn[L[i]][R[i]] = i;
        for (int k = 0; k <= L[i]; k++) {
            badlef[k][L[i]]++;
            badlef[k][R[i]]--;
        }
        if (R[i] + 1 < un.size())
            for (int k = L[i] + 1; k <= R[i]; k++)
                badlef[k][R[i] + 1]++;
        for (int k = R[i]; k < un.size(); k++) {
            badrig[k][R[i]]++;
            badrig[k][L[i]]--;
        }
        if (L[i] - 1 >= 0)
            for (int k = R[i] - 1; k >= L[i]; k--)
                badrig[k][L[i] - 1]++;
    }
    for (int i = 0; i < un.size(); i++) {
        int curlef = 0;
        for (int j = 0; j < un.size(); j++) {
            curlef += badlef[i][j];
            if (curlef > 0) bad[i][j] = true;
        }
    }
    for (int i = 0; i < un.size(); i++) {
        int currig = 0;
        for (int j = int(un.size()) - 1; j >= 0; j--) {
            currig += badrig[i][j];
            if (currig > 0) bad[j][i] = true;
        }
    }
    for (int i = n - 1; i > 0; i--)
        for (int j = i + 1; j <= n; j++)
            if (R[j] < L[i] || R[i] < L[j] || L[i] < L[j] && R[j] < R[i]) ;
            else { printf("0\n"); return 0; }
    for (int i = 0; i < un.size(); i++)
        dp[i][i] = 1;
    for (int l = 1; l <= un.size(); l++)
        for (int i = 0, j = l; j < un.size(); i++, j++) {
            mn[i][j] = min(min(mn[i + 1][j], mn[i][j - 1]), mn[i][j]);
            if (mn[i][j] < Maxn) {
                int x = mn[i][j];
                int lef = 0, rig = 0;
                for (int k = L[x]; k >= i; k--) if (!Bad(k, L[x] - 1) && !Bad(i, k - 1) && myL[x] <= k)
                    lef = (lef + ll(Get(i, k - 1)) * Get(k, L[x] - 1)) % mod;
                for (int k = R[x]; k <= j; k++) if (!Bad(R[x] + 1, k) && !Bad(k + 1, j) && k <= myR[x])
                    rig = (rig + ll(Get(R[x] + 1, k)) * Get(k + 1, j)) % mod;
                dp[i][j] = ll(lef) * rig % mod * Get(L[x] + 1, R[x] - 1) % mod;
            } else dp[i][j] = 1;
        }
    cout << dp[0][int(un.size()) - 1] << endl;
    return 0;
}