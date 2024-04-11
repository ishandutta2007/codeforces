#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;

int T;
int n, m;
char B[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        fill(B + 1, B + m + 1, 'B'); B[m + 1] = '\0';
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            int b = m + 1 - a;
            if (a > b) swap(a, b);
            if (B[a] == 'B') B[a] = 'A';
            else B[b] = 'A';
        }
        printf("%s\n", B + 1);
    }
    return 0;
}