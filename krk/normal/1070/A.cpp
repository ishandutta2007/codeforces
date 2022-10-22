#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 5015;
const int Maxm = 505;
const int Inf = 1000000000;

int s, d;
vector <ii> toup[Maxm];
int has[Maxn][Maxm];

int main()
{
    scanf("%d %d", &d, &s);
    for (int i = 0; i < d; i++)
        for (int j = 0; j < 10; j++) {
            int nw = (10 * i + j) % d;
            toup[nw].push_back(ii(i, j));
        }
    fill((int*)has, (int*)has + Maxn * Maxm, Inf);
    has[0][0] = 0;
    priority_queue <iii> Q; Q.push(iii(0, ii(0, 0)));
    while (!Q.empty()) {
        ii v = Q.top().second; int d = -Q.top().first; Q.pop();
        if (has[v.first][v.second] != d) continue;
        for (int i = 0; i < toup[v.second].size(); i++) {
            ii u = toup[v.second][i];
            ii nxt = ii(v.first + u.second, u.first);
            if (nxt.first <= s && d + 1 < has[nxt.first][nxt.second]) {
                has[nxt.first][nxt.second] = d + 1;
                Q.push(iii(-has[nxt.first][nxt.second], nxt));
            }
        }
    }
    if (has[s][0] >= Inf) { printf("-1\n"); return 0; }
    int a = s, b = 0;
    while (has[a][b] > 0) {
        int my = has[a][b];
        for (int i = 0; ; i++)
            if (has[a - i][(10 * b + i) % d] == my - 1) {
                printf("%d", i);
                a -= i; b = (10 * b + i) % d;
                break;
            }
    }
    printf("\n");
    return 0;
}