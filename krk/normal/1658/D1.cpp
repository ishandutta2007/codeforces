#include <bits/stdc++.h>
using namespace std;

const int Maxb = 17;

int T;
int zers[Maxb], ones[Maxb];
int nones[Maxb];

int main()
{
    scanf("%d", &T);
    while (T--) {
        int l, r; scanf("%d %d", &l, &r);
        for (int i = 0; i < Maxb; i++)
            zers[i] = ones[i] = nones[i] = 0;
        for (int i = l; i <= r; i++) {
            for (int j = 0; j < Maxb; j++)
                if (i & 1 << j) nones[j]++;
            int a; scanf("%d", &a);
            for (int j = 0; j < Maxb; j++)
                if (a & 1 << j) ones[j]++;
                else zers[j]++;
        }
        int res = 0;
        for (int b = 0; b < Maxb; b++)
            if (nones[b] != ones[b]) res |= 1 << b;
        printf("%d\n", res);
    }
    return 0;
}