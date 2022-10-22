#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int q;
char s[Maxn];
int slen;

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%s", s);
        slen = strlen(s);
        int U = 0, D = 0, L = 0, R = 0;
        for (int i = 0; i < slen; i++)
            if (s[i] == 'U') U++;
            else if (s[i] == 'D') D++;
            else if (s[i] == 'L') L++;
            else if (s[i] == 'R') R++;
        int tk = min(L, R); L = tk; R = tk;
        tk = min(U, D); U = tk; D = tk;
        if (U == 0 && L > 1) L = R = 1;
        if (L == 0 && U > 1) U = D = 1;
        printf("%d\n", L + R + U + D);
        for (int i = 0; i < L; i++)
            printf("L");
        for (int i = 0; i < U; i++)
            printf("U");
        for (int i = 0; i < R; i++)
            printf("R");
        for (int i = 0; i < D; i++)
            printf("D");
        printf("\n");
    }
    return 0;
}