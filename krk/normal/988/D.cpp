#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxb = 31;

int n;
int x[Maxn];
int best;
int ba, bb, bc;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    sort(x, x + n);
    best = 1; ba = x[0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < Maxb; j++) {
            int ind = lower_bound(x, x + n, x[i] + (1 << j)) - x;
            if (ind < n && x[ind] == x[i] + (1 << j)) {
                if (2 > best) { best = 2; ba = x[i]; bb = x[ind]; }
                int ind2 = lower_bound(x, x + n, x[ind] + (1 << j)) - x;
                if (ind2 < n && x[ind2] == x[ind] + (1 << j)) {
                    best = 3; ba = x[i]; bb = x[ind]; bc = x[ind2];
                }
            }
        }
    printf("%d\n", best);
    printf("%d", ba);
    if (best >= 2) printf(" %d", bb);
    if (best >= 3) printf(" %d", bc);
    printf("\n");
    return 0;
}