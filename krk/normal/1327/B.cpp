#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
bool tk[Maxn];
int lft;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            tk[i] = false;
        lft = 0;
        for (int i = 1; i <= n; i++) {
            int k; scanf("%d", &k);
            bool has = false;
            for (int j = 0; j < k; j++) {
                int a; scanf("%d", &a);
                if (!has && !tk[a])
                    has = tk[a] = true;
            }
            if (!has) lft = i;
        }
        if (!lft) printf("OPTIMAL\n");
        else {
            printf("IMPROVE\n");
            int i = 1;
            while (tk[i]) i++;
            printf("%d %d\n", lft, i);
        }
    }
    return 0;
}