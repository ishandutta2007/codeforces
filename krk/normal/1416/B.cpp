#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 10005;

int T;
int n;
int a[Maxn];
vector <iii> res;

void Do(int i, int j, int x)
{
    res.push_back(iii(ii(i, j), x));
    a[i] -= x * i;
    a[j] += x * i;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        if (sum % n != 0) { printf("-1\n"); continue; }
        res.clear();
        bool ch = true;
        while (ch) {
            ch = false;
            for (int i = 2; i <= n; i++) if (a[i] > 0)
                if (a[i] % i == 0) {
                    ch = true;
                    Do(i, 1, a[i] / i);
                } else {
                    int nd = i - a[i] % i;
                    if (a[1] >= nd) {
                        ch = true;
                        Do(1, i, nd);
                        Do(i, 1, a[i] / i);
                    }
                }
            if (ch) continue;
            for (int i = 2; i <= n && !ch; i++) if (a[i] > 0)
                if (a[i] >= i) {
                    ch = true;
                    Do(i, 1, a[i] / i);
                    int nd = i - a[i] % i;
                    Do(1, i, nd);
                    Do(i, 1, a[i] / i);
                }
        }
        int avg = sum / n;
        bool nonzer = false;
        for (int i = 2; i <= n && !nonzer; i++) if (a[i] > avg)
            nonzer = true;
        if (nonzer) { printf("-1\n"); continue; }
        for (int i = 2; i <= n; i++) if (a[i] < avg)
            Do(1, i, avg - a[i]);
        printf("%d\n", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            printf("%d %d %d\n", res[i].first.first, res[i].first.second, res[i].second);
    }
    return 0;
}