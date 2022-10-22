#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;

int T;
int n;
int a[Maxn];
int b[Maxn];
vector <ii> res;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        res.clear();
        for (int i = 0; i < n; i++) {
            int wth = i;
            for (int j = i + 1; j < n; j++)
                if (ii(a[j], b[j]) < ii(a[wth], b[wth]))
                    wth = j;
            if (wth != i) {
                res.push_back(ii(i, wth));
                swap(a[i], a[wth]);
                swap(b[i], b[wth]);
            }
        }
        bool ok = true;
        for (int i = 0; i + 1 < n && ok; i++)
            ok = a[i] <= a[i + 1] && b[i] <= b[i + 1];
        if (!ok) { printf("-1\n"); continue; }
        printf("%d\n", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            printf("%d %d\n", res[i].first + 1, res[i].second + 1);
    }
    return 0;
}