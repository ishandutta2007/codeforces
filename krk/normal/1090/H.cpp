#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 20;

int slen;
char str[Maxn];
ii my[Maxn];
vector <ii> V[Maxn][Maxm];
int res[Maxn][Maxm];

int main()
{
    scanf("%d", &slen);
    scanf("%s", str);
    for (int i = slen - 1; i >= 0; i--) {
        int sum = str[i] - '0';
        if (i) {
            sum += str[i - 1] - '0';
            my[i] = ii(sum % 2 == 0, sum % 2 == 1);
            V[i - 1][1].push_back(my[i]);
        }
    }
    for (int j = 2; j < Maxm; j++) {
        for (int i = 0; i + (1 << j) <= slen; i++) {
            int oi = i + (1 << j - 1);
            V[i][j].resize(V[i][j - 1].size());
            for (int z = 0; z < V[i][j - 1].size(); z++) {
                V[i][j][z].first = V[i][j - 1][z].first + V[oi][j - 1][z].first;
                V[i][j][z].second = V[i][j - 1][z].second + V[oi][j - 1][z].second;
                res[i][j] += min(V[i][j][z].first, V[i][j][z].second);
            }
            V[i][j].push_back(my[oi]);
            res[i][j] = (res[i][j] + 1) / 2;
        }
        for (int i = 0; i + (1 << j - 1) <= slen; i++)
            V[i][j - 1].clear();
    }
    int q; scanf("%d", &q);
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        int sz = r - l + 1;
        int p = 1;
        while (1 << p < sz) p++;
        printf("%d\n", res[l][p]);
    }
    return 0;
}