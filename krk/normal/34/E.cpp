#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;

typedef long double ld;

const int Maxn = 10;
const ld eps = 1e-9L;
const ld Inf = 1e9L;

int n;
ld curt, t;
ld x[Maxn], m[Maxn], v[Maxn];
ld meet[Maxn][Maxn];
priority_queue <pair <ld, pair <int, int> > > Q;

void Calc(int i)
{
     for (int j = 0; j < n; j++) {
         meet[i][j] = fabs(v[i] - v[j]) < eps? Inf: curt + (x[j] - x[i]) / (v[i] - v[j]);
         if (meet[i][j] <= curt + eps) meet[i][j] = Inf;
         meet[j][i] = meet[i][j];
         Q.push(make_pair(-meet[i][j], make_pair(i, j)));
     }
}

void Bum(int i, int j, ld nt)
{
     for (int l = 0; l < n; l++) x[l] += v[l] * (nt - curt);
     ld c = v[i];
     v[i] = ((m[i] - m[j]) * v[i] + 2.0 * m[j] * v[j]) / (m[i] + m[j]);
     v[j] = ((m[j] - m[i]) * v[j] + 2.0 * m[i] * c) / (m[j] + m[i]);
     curt = nt;
     Calc(i); Calc(j); 
}

int main()
{
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> x[i] >> v[i] >> m[i];
    for (int i = 0; i < n; i++) Calc(i);
    while (!Q.empty()) {
          ld nt = -Q.top().first; pair <int, int> p = Q.top().second; Q.pop();
          if (nt + eps >= t) break;
          if (fabs(meet[p.first][p.second] - nt) > eps) continue;
          Bum(p.first, p.second, nt);
    }
    cout << fixed << setprecision(9);
    for (int i = 0; i < n; i++)
        cout << x[i] + v[i] * (t - curt) << endl;
    return 0;
}