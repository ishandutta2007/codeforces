#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxk = 505;
const int Inf = 1000000000;

int T;
int n, k;
int H[Maxk][Maxk];
int V[Maxk][Maxk];
int dist[Maxk][Maxk];

void Fix(int &r1, int &c1, int &r2, int &c2)
{
    if (r1 > r2 || r1 == r2 && c1 > c2) {
        swap(r1, r2);
        swap(c1, c2);
    }
}

int costH(int r, int c)
{
    int r2 = k - 1 - r;
    int c2 = k - c;
    return H[r][c] + H[r2][c2];
}

int costV(int r, int c)
{
    int r2 = k - r;
    int c2 = k - 1 - c;
    return V[r][c] + V[r2][c2];
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        fill((int*)dist, (int*)dist + Maxk * Maxk, Inf);
        fill((int*)H, (int*)H + Maxk * Maxk, 0);
        fill((int*)V, (int*)V + Maxk * Maxk, 0);
        for (int i = 0; i < n; i++) {
            int r1, c1, r2, c2; scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
            r1--; c1--; r2--; c2--;
            Fix(r1, c1, r2, c2);
            if (r1 == r2) H[r1][c2]++;
            else V[r2][c1]++;
        }
        dist[k / 2][k / 2] = 0;
        priority_queue <iii> Q; Q.push(iii(0, ii(k / 2, k / 2)));
        int ans;
        while (!Q.empty()) {
            int d = -Q.top().first;
            ii v = Q.top().second; Q.pop();
            if (dist[v.first][v.second] != d) continue;
            if (v.first == 0 || v.first == k || v.second == 0 || v.second == k) {
                ans = d; break;
            }
            ii u = ii(v.first - 1, v.second);
            int cand = d + costH(v.first - 1, v.second);            
            if (cand < dist[u.first][u.second]) {
                dist[u.first][u.second] = cand;
                Q.push(iii(-cand, u));
            }
            u = ii(v.first + 1, v.second);
            cand = d + costH(v.first, v.second);
            if (cand < dist[u.first][u.second]) {
                dist[u.first][u.second] = cand;
                Q.push(iii(-cand, u));
            }
            u = ii(v.first, v.second - 1);
            cand = d + costV(v.first, v.second - 1);
            if (cand < dist[u.first][u.second]) {
                dist[u.first][u.second] = cand;
                Q.push(iii(-cand, u));
            }
            u = ii(v.first, v.second + 1);
            cand = d + costV(v.first, v.second);
            if (cand < dist[u.first][u.second]) {
                dist[u.first][u.second] = cand;
                Q.push(iii(-cand, u));
            }
        }
        printf("%d\n", n - ans);
    }
    return 0;
}