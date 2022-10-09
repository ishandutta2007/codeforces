#include <bits/stdc++.h>
using namespace std;
int tab[110][110];

int main()
{
    int all, a, b;
    cin >> all >> a >> b;
    int res = 1, les = 2;
    for (int i=1; i<=a; ++i)
        for (int j=1; j<=b; ++j)
        if ((i + j) % 2 == 0) tab[i][j] = res, res += 2;
        else tab[i][j] = les, les += 2;
    if (les <= all || res <= all) {
        cout << "-1";
        exit(0);
    }
    for (int i=1; i<=a; ++i) {
      for (int j=1; j<=b; ++j)
        if (tab[i][j] > 0 && tab[i][j] <= all) printf("%d ", tab[i][j]);
        else printf("0 ");
        puts("");
    }
}