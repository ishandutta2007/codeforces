#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const int Maxn = 12;
const int Maxm = 105;

int n, m, k;
string s;
int a[Maxn][Maxm], b[Maxn][Maxm], c[Maxn][Maxm];
int res;

int main()
{
    scanf("%d %d %d", &n, &m, &k); getline(cin, s);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        for (int j = 0; j < m; j++) scanf("%d %d %d", &a[i][j], &b[i][j], &c[i][j]);
        getline(cin, s);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) if (i != j) {
            int cand = 0;
            priority_queue <int> Q;
            for (int l = 0; l < m; l++)
                for (int k = 0; k < c[i][l]; k++) Q.push(b[j][l] - a[i][l]);
            for (int l = 0; l < k && !Q.empty() && Q.top() > 0; l++) {
                cand += Q.top(); Q.pop();
            }
            res = max(res, cand);
        }
    printf("%d\n", res);
    return 0;
}