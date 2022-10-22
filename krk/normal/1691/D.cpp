#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxm = 20;
const ll Inf = 1000000000000000000ll;

int T;
int n;
vector <int> S;
int a[Maxn];
int L[Maxn], R[Maxn];
ll sum[Maxn];
ll mx[Maxn][Maxm], mn[Maxn][Maxm];

ll getMax(int a, int b)
{
    ll res = -Inf;
    for (int i = Maxm - 1; i >= 0; i--)
        if (a + (1 << i) <= b + 1) {
            res = max(res, mx[a][i]);
            a += 1 << i;
        }
    return res;
}

ll getMin(int a, int b)
{
    ll res = Inf;
    for (int i = Maxm - 1; i >= 0; i--)
        if (a + (1 << i) <= b + 1) {
            res = min(res, mn[a][i]);
            a += 1 << i;
        }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum[i] = sum[i - 1] + a[i];
            mx[i][0] = mn[i][0] = sum[i];
            while (!S.empty() && a[S.back()] < a[i]) {
                R[S.back()] = i - 1;
                S.pop_back();
            }
            L[i] = S.empty()? 0: S.back();
            S.push_back(i);
        }
        while (!S.empty()) {
            R[S.back()] = n;
            S.pop_back();
        }
        for (int j = 1; j < Maxm; j++)
            for (int i = 0; i + (1 << j) <= n + 1; i++) {
                mx[i][j] = max(mx[i][j - 1], mx[i + (1 << j - 1)][j - 1]);
                mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
            }
        bool ok = true;
        for (int i = 1; i <= n && ok; i++)
            ok = a[i] >= getMax(i, R[i]) - getMin(L[i], i - 1);
        printf("%s\n", ok? "YES": "NO");
    }

    return 0;
}