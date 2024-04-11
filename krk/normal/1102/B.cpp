#include <bits/stdc++.h>
using namespace std;

const int Maxm = 5005;

int n, k;
vector <int> V[Maxm];
int res[Maxm];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        V[a].push_back(i);
    }
    int cur = 1;
    for (int i = 0; i < Maxm; i++)
        if (V[i].size() > k) { printf("NO\n"); return 0; }
        else for (int j = 0; j < V[i].size(); j++) {
            res[V[i][j]] = cur;
            cur = cur % k + 1;
        }
    printf("YES\n");
    for (int i = 0; i < n; i++)
        printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}