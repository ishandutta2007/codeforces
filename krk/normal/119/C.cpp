#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 52;
const int Maxk = 105;

struct sub {
       ll a, b;
       int c, id;
       bool operator <(const sub &s) const {
            return c < s.c;
       }
};

int n, m, k;
vector <sub> V;
ll res[Maxn][Maxk][Maxn];
pair <int, int> p[Maxn][Maxk][Maxn];

void Add(int i1, int i2, int i3, int j1, int j2, int j3, ll have)
{
    if (i2 >= 0 && i2 <= V[i1].b - V[i1].a && res[i1][i2][i3] != -1 &&
        (res[j1][j2][j3] == -1 || res[i1][i2][i3] + have > res[j1][j2][j3])) {
                         res[j1][j2][j3] = res[i1][i2][i3] + have;
                         p[j1][j2][j3] = make_pair(i1, i2);
    }
}

void Print(int i, int j, int k)
{
     if (k > 1) Print(p[i][j][k].first, p[i][j][k].second, k - 1);
     cout << V[i].id << " " << V[i].a + ll(j) << endl;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        sub s; s.id = i;
        cin >> s.a >> s.b >> s.c;
        V.push_back(s);
    }
    sort(V.begin(), V.end());
    fill((ll*)res, (ll*)res + Maxn * Maxk * Maxn, -1);
    for (int i = 0; i < m; i++)
       for (int j = 0; j <= V[i].b - V[i].a; j++) {
           ll have = V[i].a + ll(j);
           res[i][j][1] = have;
           for (int l = 2; l <= n; l++)
              for (int pr = 0; pr < i && V[pr].c < V[i].c; pr++) {
                  if (have % ll(k) == 0LL) Add(pr, have / ll(k) - V[pr].a, l - 1, i, j, l, have);
                  Add(pr, have - ll(k) - V[pr].a, l - 1, i, j, l, have);
              }
       }
    int bi = 0, bj = 0;
    for (int i = 0; i < m; i++)
       for (int j = 0; j <= V[i].b - V[i].a; j++)
          if (res[i][j][n] > res[bi][bj][n]) {
                           bi = i; bj = j;
          }
    if (res[bi][bj][n] == -1) cout << "NO\n";
    else {
         cout << "YES\n";
         Print(bi, bj, n);
    }
    return 0;
}