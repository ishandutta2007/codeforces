#include <bits/stdc++.h>
using namespace std;

const int Maxb = 8;

int t;
int n;

int Ask(const vector <int> &V1, const vector <int> &V2)
{
    if (V1.empty() || V2.empty()) return 0;
    printf("%d %d", int(V1.size()), int(V2.size()));
    for (int i = 0; i < V1.size(); i++)
        printf(" %d", V1[i]);
    for (int i = 0; i < V2.size(); i++)
        printf(" %d", V2[i]);
    printf("\n"); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int res = 0;
        for (int i = 0; i < Maxb; i++) {
            vector <int> V1, V2;
            for (int j = 1; j <= n; j++)
                if (j & 1 << i) V1.push_back(j);
                else V2.push_back(j);
            res = max(res, Ask(V1, V2));
        }
        printf("-1 %d\n", res); fflush(stdout);
    }
    return 0;
}