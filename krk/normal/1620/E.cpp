#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;

int q;
int my[Maxn];
int P[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &q);
    int k = 0;
    while (q--) {
        int typ, a, b; scanf("%d %d", &typ, &a);
        if (typ == 1) {
            k++;
            if (my[a] > 0) P[my[a]] = k;
            my[a] = k;
        } else {
            scanf("%d", &b);
            if (my[a] > 0 && my[b] > 0) {
                int u = my[a], v = my[b];
                my[a] = 0;
                if (u > v) swap(u, v);
                P[u] = v;
                my[b] = v;
            } else if (my[a] > 0) {
                my[b] = my[a];
                my[a] = 0;
            }
        }
    }
    for (int i = 0; i < Maxn; i++)
        if (my[i] > 0) res[my[i]] = i;
    for (int i = k; i > 0; i--)
        if (P[i]) res[i] = res[P[i]];
    for (int i = 1; i <= k; i++)
        printf("%d%c", res[i], i + 1 <= k? ' ': '\n');
    return 0;
}