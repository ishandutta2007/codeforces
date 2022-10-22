#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        if (n > m) { printf("No\n"); continue; }
        vector <int> res;
        if (n % 2) {
            for (int i = 0; i < n - 1; i++)
                res.push_back(1);
            res.push_back(m - (n - 1));
        } else if (m % 2) {
            printf("No\n");
            continue;
        } else {
            for (int i = 0; i < n - 2; i++)
                res.push_back(1);
            int lft = (m - (n - 2)) / 2;
            res.push_back(lft);
            res.push_back(lft);
        }
        printf("Yes\n");
        for (int i = 0; i < res.size(); i++)
            printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}