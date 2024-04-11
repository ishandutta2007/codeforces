#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;

int T;
int n, m;
char B[Maxn][Maxn];
vector <ii> res1, res2;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%s", B[i]);
        if (B[0][0] == '1') {
            printf("-1\n");
            continue;
        }
        res1.clear(); res2.clear();
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--) if (B[i][j] == '1')
                if (i > 0) {
                    res1.push_back(ii(i - 1, j));
                    res2.push_back(ii(i, j));
                } else {
                    res1.push_back(ii(i, j - 1));
                    res2.push_back(ii(i, j));
                }
        printf("%d\n", int(res1.size()));
        for (int i = 0; i < res1.size(); i++)
            printf("%d %d %d %d\n", res1[i].first + 1, res1[i].second + 1, res2[i].first + 1, res2[i].second + 1);
    }
    return 0;
}