#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int mod = 1000000007;

int T;
int n;
vector <int> neigh[Maxn];
int cnt[Maxn];
vector <ll> seq;
vector <int> P;

void Count(int v, int p)
{
    cnt[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Count(u, v);
        seq.push_back(ll(cnt[u]) * (n - cnt[u]));
        cnt[v] += cnt[u];
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        seq.clear();
        Count(1, 0);
        sort(seq.begin(), seq.end());
        int m; scanf("%d", &m);
        P.clear();
        for (int i = 0; i < m; i++) {
            int a; scanf("%d", &a);
            P.push_back(a);
        }
        while (P.size() < seq.size()) P.push_back(1);
        sort(P.begin(), P.end());
        while (P.size() > seq.size()) {
            int sav = P.back(); P.pop_back();
            P.back() = ll(P.back()) * sav % mod;
        }
        int res = 0;
        for (int i = 0; i < seq.size(); i++)
            res = (res + seq[i] % mod * ll(P[i])) % mod;
        printf("%d\n", res);
    }
    return 0;
}