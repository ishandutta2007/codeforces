#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxb = 62;
const int Inf = 1000000000;
const int Maxm = 2 * Maxb;

int n;
ll a[Maxn];
vector <int> my[Maxb];
vector <int> un;
int prv[Maxm][Maxm];
int dist[Maxm][Maxm];

int Check(int a, int b)
{
    for (int i = 0; i < un.size(); i++)
        for (int j = 0; j < un.size(); j++)
            dist[i][j] = prv[i][j];
    for (int k = 0; k < un.size(); k++)
        for (int i = 0; i < un.size(); i++)
            for (int j = 0; j < un.size(); j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    if (dist[a][b] >= Inf) return Inf;
    return dist[a][b] + 1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
        for (int j = 0; j < Maxb; j++)
            if (a[i] & 1ll << ll(j))
                my[j].push_back(i);
    }
    for (int i = 0; i < Maxb; i++)
        if (my[i].size() > 2) { printf("3\n"); return 0; }
        else if (my[i].size() == 2) {
            un.push_back(my[i][0]);
            un.push_back(my[i][1]);
        }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    fill((int*)prv, (int*)prv + Maxm * Maxm, Inf);
    for (int i = 0; i < un.size(); i++)
        prv[i][i] = 0;
    for (int i = 0; i < Maxb; i++)
        if (my[i].size() == 2) {
            int ind1 = lower_bound(un.begin(), un.end(), my[i][0]) - un.begin();
            int ind2 = lower_bound(un.begin(), un.end(), my[i][1]) - un.begin();
            prv[ind1][ind2] = prv[ind2][ind1] = 1;
        }
    int res = Inf;
    for (int a = 0; a < un.size(); a++)
        for (int b = a + 1; b < un.size(); b++) if (prv[a][b] == 1) {
            prv[a][b] = prv[b][a] = Inf;
            res = min(res, Check(a, b));
            prv[a][b] = prv[b][a] = 1;
        }
    if (res >= Inf) printf("-1\n");
    else printf("%d\n", res);
    return 0;
}