#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;
typedef pair <ll, ll> llll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 200005;

int T;
int n, m;
int a[Maxn];
vector <ii> tmp;
vector <ii> seq;
ll dp[Maxn][3];

int getNext(int x)
{
    return lower_bound(seq.begin(), seq.end(), ii(x, 0)) - seq.begin();
}

int getPrev(int x)
{
    return getNext(x) - 1;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        tmp.clear();
        seq.clear();
        for (int i = 0; i < m; i++) {
            int l, r; scanf("%d %d", &l, &r);
            int ind = lower_bound(a, a + n, l) - a;
            if (ind < n && a[ind] <= r) continue;
            tmp.push_back(ii(l, r));
        }
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < tmp.size(); i++) {
            while (!seq.empty() && seq.back().second >= tmp[i].second)
                seq.pop_back();
            seq.push_back(tmp[i]);
        }
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= 2; j++)
                dp[i][j] = Inf;
        ll res = Inf;
        int ind = getNext(a[0]);
        if (ind > 0) {
            dp[0][1] = a[0] - seq[0].second;
            dp[0][2] = 2ll * (a[0] - seq[0].second);
        } else dp[0][1] = dp[0][2] = 0;
        for (int i = 0; i + 1 < n; i++) {
            int l = getNext(a[i]), r = getPrev(a[i + 1]);
            for (int j = l - 1; j <= r; j++) {
                ll fir = j >= l? seq[j].first: a[i], sec = j < r? seq[j + 1].second: a[i + 1];
                ll best = min(dp[i][1] + 2ll * (fir - a[i]), dp[i][2] + (fir - a[i]));
                dp[i + 1][1] = min(dp[i + 1][1], best + (a[i + 1] - sec));
                dp[i + 1][2] = min(dp[i + 1][2], best + 2ll * (a[i + 1] - sec));
            }
        }
        ind = getNext(a[n - 1]);
        if (ind < seq.size())
            res = min(dp[n - 1][1] + 2ll * (seq.back().first - a[n - 1]),
                      dp[n - 1][2] + (seq.back().first - a[n - 1]));
        else res = min(dp[n - 1][1], dp[n - 1][2]);
        printf("%I64d\n", res);
    }
    return 0;
}