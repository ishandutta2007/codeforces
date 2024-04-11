#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, m;
vector <int> best[Maxn];
int res[Maxn];
int ans;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int s, r; scanf("%d %d", &s, &r);
        best[s].push_back(r);
    }
    for (int i = 1; i <= m; i++) {
        sort(best[i].rbegin(), best[i].rend());
        int sum = 0;
        for (int j = 0; j < best[i].size(); j++) {
            sum += best[i][j];
            if (sum > 0)
                res[j + 1] += sum;
        }
    }
    for (int i = 0; i <= n; i++)
        ans = max(ans, res[i]);
    printf("%d\n", ans);
    return 0;
}