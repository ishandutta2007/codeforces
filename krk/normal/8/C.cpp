#include <iostream>
#include <algorithm>
using namespace std;

const int Inf = 2000000000;
const int Maxn = 24;

int xs, ys;
int n;
int x[Maxn], y[Maxn];
bool both[Maxn][Maxn];
int pth[Maxn][Maxn];
int best[1 << Maxn];
pair <int, int> p[1 << Maxn];

int Len(int x1, int y1, int x2, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void Print(int x)
{
    if (p[x].first != -1) {
                   int prv = x & ~(1 << p[x].first);
                   if (p[x].second != -1) prv &= ~(1 << p[x].second);
                   Print(prv);
                   if (p[x].second == -1) cout << " " << p[x].first + 1 << " ";
                   else {
                        cout << " " << p[x].first + 1 << " ";
                        if (!both[p[x].first][p[x].second]) cout << "0 ";
                        cout << p[x].second + 1 << " ";
                   }
    }
    cout << "0";
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> xs >> ys;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++)
       for (int j = i + 1; j < n; j++) {
           int res1 = 2 * Len(xs, ys, x[i], y[i]) + 2 * Len(xs, ys, x[j], y[j]);
           int res2 = Len(xs, ys, x[i], y[i]) + Len(x[i], y[i], x[j], y[j]) + Len(x[j], y[j], xs, ys);
           if (res2 <= res1) {
                    both[i][j] = true;
                    pth[i][j] = res2;
           } else pth[i][j] = res1;
       }
    best[0] = 0; p[0] = make_pair(-1, -1);
    fill(best + 1, best + (1 << n), Inf);
    for (int i = 0; i < (1 << n) - 1; i++) if (best[i] != Inf) {
        int j = 0;
        while (i & 1 << j) j++;
        for (int l = j + 1; l < n; l++) if (!(i & 1 << l)) {
            int where = i | 1 << j | 1 << l;
            int curbest = best[i] + pth[j][l];
            if (curbest < best[where]) {
                        best[where] = curbest;
                        p[where] = make_pair(j, l);
            }
        }
        int where = i | 1 << j;
        int curbest = best[i] + 2 * Len(xs, ys, x[j], y[j]);
        if (curbest < best[where]) {
                    best[where] = curbest;
                    p[where] = make_pair(j, -1);
        }
    }
    cout << best[(1 << n) - 1] << endl;
    Print((1 << n) - 1); cout << endl;
    return 0;
}