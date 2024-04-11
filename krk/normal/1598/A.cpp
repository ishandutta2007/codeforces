#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int t;
int n;
char S[2][Maxn];

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < 2; i++)
            scanf("%s", S[i]);
        bool ok = true;
        for (int j = 0; j < n; j++)
            if (S[0][j] == '1' && S[1][j] == '1')
                ok = false;
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}