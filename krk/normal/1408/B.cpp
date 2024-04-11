#include <bits/stdc++.h>
using namespace std;

int T;
int n, k;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        set <int> S;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            S.insert(a);
        }
        int siz = S.size();
        if (siz > 1 && k == 1) printf("-1\n");
        else {
            int res = 1;
            siz -= k;
            while (siz > 0) {
                res++;
                siz -= (k - 1);
            }
            printf("%d\n", res);
        }
    }
    return 0;
}