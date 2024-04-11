#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int sav[Maxn];
int n, m;
vector <int> X;
int lim = 1000000000;
int res;
int ans = 1000005;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        X.push_back(x);
    }
    X.push_back(lim);
    sort(X.begin(), X.end());
    for (int i = 0; i < m; i++) {
        int x1, x2, y; scanf("%d %d %d", &x1, &x2, &y);
        if (x1 == 1) {
            res++;
            sav[upper_bound(X.begin(), X.end(), x2) - X.begin()]++;
        }
    }
    for (int i = 0; i < X.size(); i++) {
        res -= sav[i];
        ans = min(ans, res + i);
    }
    printf("%d\n", ans);
    return 0;
}