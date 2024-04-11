#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
map <int, int> M;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        M.clear();
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            M[a]++;
        }
        int mx = 0;
        for (auto p: M)
            mx = max(mx, p.second);
        int res = 0;
        while (mx < n) {
            res++;
            int to = 2 * mx;
            res += min(to, n) - mx;
            mx = to;
        }
        printf("%d\n", res);
    }
    return 0;
}