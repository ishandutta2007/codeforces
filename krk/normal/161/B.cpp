#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1005;

int n, k;
int cost[Maxn];
vector <int> V[2];
int took = 0;
vector <int> res[Maxn];
int lst[Maxn];

bool Less(const int &a, const int &b)
{
    return cost[a] < cost[b];
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        int c, t; scanf("%d %d", &c, &t);
        cost[i] = c;
        V[t - 1].push_back(i);
    }
    sort(V[0].rbegin(), V[0].rend(), Less);
    sort(V[1].begin(), V[1].end(), Less);
    for (int i = 0; i < V[0].size(); i++)
        if (took == k) {
            res[k - 1].push_back(V[0][i]);
            lst[k - 1] = cost[V[0][i]];
        } else {
            res[took].push_back(V[0][i]);
            lst[took++] = cost[V[0][i]];
        }
    for (int i = 0; i < V[1].size(); i++)
        if (took + V[1].size() - i == k) {
            res[took].push_back(V[1][i]);
            lst[took++] = -1;
        } else {
            int j = 0;
            while (j < took && cost[V[1][i]] < lst[j]) j++;
            if (j == took)
                if (took == k) {
                    res[k - 1].push_back(V[1][i]);
                    lst[k - 1] = cost[V[1][i]];
                } else {
                    res[took].push_back(V[1][i]);
                    lst[took++] = -1;
                }
            else res[j].push_back(V[1][i]);
        }
    ll ans = 0LL;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < res[i].size(); j++)
            ans += 2 * cost[res[i][j]];
        if (lst[i] != -1) ans -= lst[i];
    }
    printf("%I64d.%s\n", ans / 2LL, ans % 2LL? "5": "0");
    for (int i = 0; i < k; i++) {
        printf("%d", res[i].size());
        for (int j = 0; j < res[i].size(); j++) printf(" %d", res[i][j]);
        printf("\n");
    }
    return 0;
}