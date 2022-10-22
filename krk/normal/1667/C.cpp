#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

int n;
vector <ii> res;

int main()
{
    scanf("%d", &n);
    while (n && n % 3 != 2) {
        res.push_back(ii(n, n));
        n--;
    }
    if (n % 3 == 2) {
        int tims = n / 3;
        for (int i = 1; i <= tims + 1; i++)
            res.push_back(ii(i, 2 * i - 1));
        int row = tims + 2, col = 2;
        for (int i = 1; i <= tims; i++) {
            res.push_back(ii(row, col));
            row++; col += 2;
        }
    }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}