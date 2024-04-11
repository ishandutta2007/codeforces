#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 20005;
const int Maxm = 20005;

int n, m, p;
int x[Maxn], y[Maxm];
int pthr[Maxn + Maxm], pthc[Maxn + Maxm];

int f(int r, int c)
{
    return (x[r] + y[c]) % p;
}

void findAns(int r1, int c1, int r2, int c2)
{
     if (r1 == r2)
        for (int j = c1; j <= c2; j++) { pthr[r1 + j] = r1; pthc[r1 + j] = j; }
     else if (c1 == c2)
        for (int i = r1; i <= r2; i++) { pthr[i + c1] = i; pthc[i + c1] = c1; }
     else {
          int from1[Maxn + Maxm] = {0};
          int from2[Maxn + Maxm] = {0};
          int k = (r1 + c1 + r2 + c2) / 2;
          from1[c1] = f(r1, c1);
          for (int d = r1 + c1 + 1; d <= k; d++)
             for (int j = c2; j >= c1; j--) 
                if (r1 <= d - j && d - j <= r2) {
                       from1[j] = max(from1[j], from1[j - 1]);
                       from1[j] += f(d - j, j);
                }
          from2[c2] = f(r2, c2);
          for (int d = r2 + c2 - 1; d >= k; d--)
             for (int j = c1; j <= c2; j++) 
                if (r1 <= d - j && d - j <= r2) {
                       from2[j] = max(from2[j], from2[j + 1]);
                       from2[j] += f(d - j, j);
                }
          int best = -1, besti = 0;
          for (int j = c1; j <= c2; j++) 
             if (r1 <= k - j && k - j <= r2) {
                    int curbest = from1[j] + from2[j] - f(k - j, j);
                    if (curbest > best) {
                                best = curbest; besti = j;
                    }
             }
          pthr[k] = k - besti; pthc[k] = besti;
          findAns(r1, c1, pthr[k], pthc[k]); 
          findAns(pthr[k], pthc[k], r2, c2);
     }
}

int main()
{
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 0; i < n; i++) scanf("%d", &x[i]);
    for (int i = 0; i < m; i++) scanf("%d", &y[i]);
    findAns(0, 0, n - 1, m - 1);
    int res = 0;
    for (int i = 0; i <= n + m - 2; i++)
       res += f(pthr[i], pthc[i]);
    printf("%d\n", res);
    for (int i = 0; i < n + m - 2; i++)
       if (pthr[i] == pthr[i + 1]) printf("S");
       else printf("C");
    printf("\n");
    return 0;
}