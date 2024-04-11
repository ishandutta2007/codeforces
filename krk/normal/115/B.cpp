#include <iostream>
using namespace std;

const int Maxn = 155;

int n, m;
char C[Maxn][Maxn];
int l[Maxn], r[Maxn];
int res;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++)
          cin >> C[i][j];
    for (int i = 0; i < n; i++) {
        l[i] = 0;
        while (l[i] < m && C[i][l[i]] != 'W') l[i]++;
        r[i] = m - 1;
        while (r[i] >= 0 && C[i][r[i]] != 'W') r[i]--;
    }
    while (n >= 1 && l[n - 1] == m && r[n - 1] < 0) n--;
    int c = 0;
    for (int i = 0; i < n; i++)
       if (i % 2 == 0) {
             if (c < r[i]) { res += r[i] - c; c = r[i]; }
             if (i + 1 < n && c < r[i + 1]) { res += r[i + 1] - c; c = r[i + 1]; }
             if (i + 1 < n) res++;
       } else {
              if (l[i] < c) { res += c - l[i]; c = l[i]; }
              if (i + 1 < n && l[i + 1] < c) { res += c - l[i + 1]; c = l[i + 1]; }
              if (i + 1 < n) res++;
       }
    cout << res << endl;
    return 0;
}