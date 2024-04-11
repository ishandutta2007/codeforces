#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int mid = 1000000;

int q;

int main()
{
    scanf("%d", &q);
    while (q--) {
        int b, w; scanf("%d %d", &b, &w);
        int x = mid, y = mid;
        if (b < w) { x++; swap(b, w); }
        vector <ii> res;
        for (int i = 0; i < w; i++) {
            res.push_back(ii(x + 2 * i, y));
            if (i) {
                res.push_back(ii(x + 2 * i - 1, y));
                b--;
            }
        }
        if (b > 0) {
            res.push_back(ii(x - 1, y));
            b--;
        }
        if (b > 0) {
            res.push_back(ii(x + 2 * w - 1, y));
            b--;
        }
        for (int i = 0; i < w; i++) {
            if (b > 0) {
                res.push_back(ii(x + 2 * i, y + 1));
                b--;
            }
            if (b > 0) {
                res.push_back(ii(x + 2 * i, y - 1));
                b--;
            }
        }
        if (b > 0) printf("NO\n");
        else {
            printf("YES\n");
            for (int i = 0; i < res.size(); i++)
                printf("%d %d\n", res[i].first, res[i].second);
        }
    }
    return 0;
}