#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const ll Inf = 1000000000000000000ll;
const int Maxn = 150005;
const int Maxm = 305;

int n, m, d;
int A[Maxm], b[Maxm], t[Maxm];
ll dp[2][Maxn];
bool cur;
vector <ii> seq;
ll res, add = -Inf;

void Insert(int a, const ii &val)
{
    while (a < seq.size() && seq.back().first <= val.first) seq.pop_back();
    seq.push_back(val);
}

int main()
{
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &A[i], &b[i], &t[i]); res += b[i];
    }
    ll dist = 0;
    for (int i = m - 1; i >= 0; i--) {
        fill(dp[cur] + 1, dp[cur] + n + 1, 0);
        seq.clear();
        int a = 0, b = 2; Insert(a, ii(dp[!cur][1], 1));
        for (int j = 1; j <= n; j++) {
            while (b <= n && b - j <= dist) { Insert(a, ii(dp[!cur][b], b)); b++; }
            while (j - seq[a].second > dist) a++;
            dp[cur][j] = -abs(j - A[i]) + seq[a].first;
        }
        cur = !cur;
        if (i) dist = ll(t[i] - t[i - 1]) * ll(d);
    }
    for (int i = 1; i <= n; i++)
        add = max(add, dp[!cur][i]);
    printf("%I64d\n", res + add);
    return 0;
}