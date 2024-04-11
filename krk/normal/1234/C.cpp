#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int q;
int n;
char S[2][Maxn];

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        for (int i = 0; i < 2; i++)
            scanf("%s", S[i]);
        int r = 0, c = 0;
        while (c < n) {
            if (S[r][c] <= '2') { c++; continue; }
            r = 1 - r;
            if (S[r][c] <= '2') break;
            c++;
        }
        if (r == 1 && c == n) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}