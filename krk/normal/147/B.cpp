#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 305;
const int Maxp = 10;

struct matrix {
       int m[Maxn][Maxn];
       void Clear() { 
            fill((int*)m, (int*)m + Maxn * Maxn, -1000000000);
            for (int i = 1; i < Maxn; i++) m[i][i] = 0;
       }
       matrix() { Clear(); }
};

matrix pow[Maxp];
matrix tmp, nw;
int n, m;
int res;

void Mult(const matrix &a, const matrix &b, matrix &c)
{
     for (int i = 1; i <= n; i++)
         for (int j = 1; j <= n; j++)
             for (int k = 1; k <= n; k++)
                 c.m[i][j] = max(c.m[i][j], a.m[i][k] + b.m[k][j]);
}

void Search(int l, int r)
{
     if (l > r) return;
     int mid = (l + r) / 2;
     int i = 0;
     while (!(mid & 1 << i)) i++;
     tmp = pow[i];
     for (i++; i < Maxp; i++)
         if (mid & (1 << i)) {
                 nw.Clear(); Mult(tmp, pow[i], nw); tmp = nw;
         }
     bool found = false;
     for (int i = 1; i <= n && !found; i++)
         if (tmp.m[i][i] > 0) found = true;
     if (found) {
                res = mid;
                Search(l, mid - 1);
     } else Search(mid + 1, r);
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        pow[0].m[a][b] = c; pow[0].m[b][a] = d;
    }
    for (int i = 1; i < Maxp; i++)
        Mult(pow[i - 1], pow[i - 1], pow[i]);
    Search(2, n);
    cout << res << endl;
    return 0;
}