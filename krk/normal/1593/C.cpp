#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000006;

int T;
int n, k;
int x[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < k; i++)
            scanf("%d", &x[i]);
        sort(x, x + k);
        int cat = 0;
        int res = 0;
        for (int i = k - 1; i >= 0 && x[i] > cat; i--) {
            res++;
            cat += n - x[i];
        }
        printf("%d\n", res);
    }
    return 0;
}