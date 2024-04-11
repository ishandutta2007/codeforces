#include <bits/stdc++.h>
using namespace std;

const int Maxn = 40001;
const int lim = 30001;

int T;
int A, B, C;

int main()
{
    scanf("%d", &T);
    while (T--) {
        int best = lim, ba, bb, bc;
        scanf("%d %d %d", &A, &B, &C);
        for (int a = 1; a < Maxn; a++) {
            int cand1 = abs(a - A);
            if (cand1 >= best) continue;
            for (int b = a; b < Maxn; b += a) {
                int cand2 = cand1 + abs(b - B);
                if (cand2 >= best) continue;
                for (int c = b; c < Maxn; c += b) {
                    int cand3 = cand2 + abs(c - C);
                    if (cand3 >= best) continue;
                    best = cand3;
                    ba = a; bb = b; bc = c;
                }
            }
        }
        printf("%d\n", best);
        printf("%d %d %d\n", ba, bb, bc);
    }
    return 0;
}