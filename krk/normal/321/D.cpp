#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 33;

int n;
int B[Maxn][Maxn];
vector <iii> neigh[2][Maxn][2];
int res;
int cand[Maxn][2];

int Get(int val, bool inv) { return inv? -val: val; }

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);
    int z = (n + 1) / 2;
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n / 2; j++)
            for (int k = 0; k < 1 << 3; k++) {
                int sum = Get(B[i][j], k & 1) + Get(B[i][j + z], k & 2) + Get(B[i + z][j], k & 4) + Get(B[i + z][j + z], k & 8);
                int ar = bool(k & 1) ^ bool(k & 2);
                int bc = bool(k & 1) ^ bool(k & 4);
                int C = bool(k & 1) ^ bool(k & 2) ^ bool(k & 4) ^ bool(k & 8);
                sum = max(sum, -sum);
                neigh[C][i][ar].push_back(iii(ii(j, bc), sum));
            }
    for (int t = 0; t < 2; t++)
        for (int k = 0; k < 1 << n / 2; k++) {
            for (int j = 0; j < n / 2; j++) {
                cand[j][0] = Get(B[n / 2][j], false) + Get(B[n / 2][j + z], t);
                cand[j][1] = Get(B[n / 2][j], true) + Get(B[n / 2][j + z], !t);
            }
            int cur = Get(B[n / 2][n / 2], t);
            for (int i = 0; i < n / 2; i++) {
                bool b = bool(k & 1 << i);
                cur += Get(B[i][n / 2], b) + Get(B[i + z][n / 2], b ^ t);
                for (int c = 0; c < neigh[t][i][b].size(); c++) {
                    auto p = neigh[t][i][b][c];
                    cand[p.first.first][p.first.second] += p.second;
                }
            }
            for (int j = 0; j < n / 2; j++)
                cur += max(cand[j][0], cand[j][1]);
            res = max(res, cur);
        }
    printf("%d\n", res);
    return 0;
}