#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 500005;
const int Inf = 1000000007;
const int Maxm = 2097152;

int n, k;
int a[Maxn];
set <ii> S;
int mx[Maxn];
int mn[Maxn];
int dp[Maxn];
vector <iii> seq;
vector <int> un;
vector <ii> st[Maxm];

void Update(int v, int l, int r, int a, int b, int val, int x)
{
    if (l == a && r == b) {
        if (st[v].empty() || st[v].back().second < x)
            st[v].push_back(ii(val, x));
    } else {
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), val, x);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, val, x);
    }
}

int Get(int v, int l, int r, int x, int val)
{
    int res;
    if (st[v].empty()) res = -Inf;
    else {
        int ind = lower_bound(st[v].begin(), st[v].end(), ii(val + 1, 0)) - st[v].begin() - 1;
        if (ind < 0) res = -Inf;
        else res = st[v][ind].second;
    }
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) res = max(res, Get(2 * v, l, m, x, val));
        else res = max(res, Get(2 * v + 1, m + 1, r, x, val));
    }
    return res;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        un.push_back(a[i]);
        mx[i] = Inf;
    }
    S.insert(ii(a[n], n));
    dp[n] = n;
    for (int i = n - 1; i >= 0; i--) {
        mn[i] = S.begin()->first;
        if (a[i] > mn[i]) dp[i] = dp[i + 1];
        else dp[i] = i;
        if (S.size() >= 2) {
            auto it = S.begin(); it++;
            if (a[i] <= it->first)
                mx[S.begin()->second] = min(mx[S.begin()->second], a[i] - 1);
        } else mx[S.begin()->second] = min(mx[S.begin()->second], a[i] - 1);
        if (i + k <= n) S.erase(ii(a[i + k], i + k));
        S.insert(ii(a[i], i));
    }
    int st = dp[0];
    if (st >= n) { printf("YES\n"); return 0; }
    sort(un.begin(), un.end());
    un.erase(unique(un.begin(), un.end()), un.end());
    for (int i = st + k + 1; i < n; i++) if (dp[i + 1] >= n && a[i] < a[st]) {
        int lef = lower_bound(un.begin(), un.end(), max(mn[i], a[i]) + 1) - un.begin();
        int rig = un.size() - 1;
        if (lef <= rig) Update(1, 0, int(un.size()) - 1, lef, rig, i, a[i]);
    }
    for (int i = st + 1; i <= st + k; i++) {
        int ind = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
        if (Get(1, 0, int(un.size()) - 1, ind, dp[i + 1]) > mn[i]) {
            printf("YES\n"); return 0;
        }
    }
    printf("NO\n");
    return 0;
}