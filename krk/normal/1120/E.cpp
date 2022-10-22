#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxd = 10;
const int nil = 5005;
const int Maxn = 10015;
const int Maxm = 1001;

int a;
int dist[Maxn][Maxm];
ii par[Maxn][Maxm];
int wth[Maxn][Maxm];
ii seq[Maxn * Maxm];
int pnt, slen;

int main()
{
    scanf("%d", &a);
    for (int i = 1; i < Maxd; i++) {
        int oth = i * a % Maxd;
        int car = i * a / Maxd;
        if (a * oth - i + nil < Maxn) {
            dist[a * oth - i + nil][car] = 1;
            par[a * oth - i + nil][car] = ii(-1, -1);
            wth[a * oth - i + nil][car] = i;
            seq[slen++] = ii(a * oth - i + nil, car);
        }
    }
    while (pnt < slen) {
        auto v = seq[pnt++];
        int d = dist[v.first][v.second];
        bool pr = false;
        if (v.first == nil && v.second == 0) {
            while (v.first != -1) {
                if (pr || wth[v.first][v.second] != 0) {
                    printf("%d", wth[v.first][v.second]);
                    pr = true;
                }
                v = par[v.first][v.second];
            }
            printf("\n");
            return 0;
        }
        for (int i = 0; i < Maxd; i++) {
            int got = i * a + v.second;
            int dig = got % Maxd;
            ii u = ii(v.first + a * dig - i, got / Maxd);
            if (u.first >= 0 && u.first < Maxn && !dist[u.first][u.second]) {
                dist[u.first][u.second] = d + 1;
                par[u.first][u.second] = v;
                wth[u.first][u.second] = i;
                seq[slen++] = u;
            }
        }
    }
    printf("-1\n");
    return 0;
}