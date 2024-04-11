#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const int mod = 998244353;

bool banned[Maxn];
vector <int> has[Maxn];
queue <int> banQ;
bool banind[Maxn];
int n, m, k;
vector <int> A[Maxn];
bool tk[Maxn];
vector <int> neigh[Maxn], rneigh[Maxn];
vector <int> seq, un;
int uncnt[Maxn];
int dp[Maxn];

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        int c; scanf("%d", &c);
        A[i].resize(c);
        for (int j = 0; j < c; j++) {
            scanf("%d", &A[i][j]);
            if (tk[A[i][j]] && !banned[A[i][j]]) {
                banned[A[i][j]] = true;
                banQ.push(A[i][j]);
            } else if (!tk[A[i][j]]) {
                tk[A[i][j]] = true;
                has[A[i][j]].push_back(i);
            }
        }
        for (int j = 0; j < c; j++)
            tk[A[i][j]] = false;
        for (int j = 0; j + 1 < c; j++) {
            neigh[A[i][j]].push_back(A[i][j + 1]);
            rneigh[A[i][j + 1]].push_back(A[i][j]);
        }
    }
    for (int i = 1; i <= k; i++) {
        sort(neigh[i].begin(), neigh[i].end());
        neigh[i].erase(unique(neigh[i].begin(), neigh[i].end()), neigh[i].end());
        sort(rneigh[i].begin(), rneigh[i].end());
        rneigh[i].erase(unique(rneigh[i].begin(), rneigh[i].end()), rneigh[i].end());
        if ((neigh[i].size() > 1 || rneigh[i].size() > 1) && !banned[i]) {
            banned[i] = true;
            banQ.push(i);
        }
    }
    while (!banQ.empty()) {
        int v = banQ.front(); banQ.pop();
        for (int i = 0; i < has[v].size(); i++) {
            int ind = has[v][i];
            if (banind[ind]) continue;
            banind[ind] = true;
            for (int j = 0; j < A[ind].size(); j++)
                if (!banned[A[ind][j]]) {
                    banned[A[ind][j]] = true;
                    banQ.push(A[ind][j]);
                }
        }
    }
    for (int i = 1; i <= k; i++) if (!banned[i] && rneigh[i].size() == 0) {
        int cnt = 1;
        int num = i;
        while (!neigh[num].empty()) {
            cnt++;
            num = neigh[num][0];
        }
        seq.push_back(cnt);
        un.push_back(cnt);
    }
    sort(un.begin(), un.end());
    un.erase(unique(un.begin(), un.end()), un.end());
    for (int i = 0; i < seq.size(); i++) {
        int ind = lower_bound(un.begin(), un.end(), seq[i]) - un.begin();
        uncnt[ind]++;
    }
    dp[0] = 1;
    for (int i = 0; i < m; i++) if (dp[i])
        for (int j = 0; j < un.size() && i + un[j] <= m; j++)
            dp[i + un[j]] = (dp[i + un[j]] + ll(dp[i]) * uncnt[j]) % mod;
    printf("%d\n", dp[m]);
    return 0;
}