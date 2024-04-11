#include <bits/stdc++.h>
using namespace std;

int T;
int n, c;
map <int, int> M;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &c);
        M.clear();
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            M[a]++;
        }
        int res = 0;
        for (auto p: M)
            res += min(c, p.second);
        printf("%d\n", res);
    }
    return 0;
}