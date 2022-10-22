#include <bits/stdc++.h>
using namespace std;

const int Maxn = 205;

int n;
char str[Maxn];
char res[Maxn];

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    char G[2] = {'a' - 1, 'a' - 1};
    for (int i = 0; i < n; i++)
        if (str[i] >= G[0] && str[i] >= G[1])
            if (G[0] >= G[1]) { res[i] = '0'; G[0] = str[i]; }
            else { res[i] = '1'; G[1] = str[i]; }
        else if (str[i] >= G[0]) { res[i] = '0'; G[0] = str[i]; }
             else if (str[i] >= G[1]) { res[i] = '1'; G[1] = str[i]; }
        else { printf("NO\n"); return 0; }
    printf("YES\n");
    res[n] = '\0';
    printf("%s\n", res);
    return 0;
}