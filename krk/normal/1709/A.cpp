#include <bits/stdc++.h>
using namespace std;

int T;
int x;
bool tk[4];
int has[4];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &x);
        for (int i = 1; i <= 3; i++) {
            scanf("%d", &has[i]);
            tk[i] = false;
        }
        while (x && !tk[x]) {
            tk[x] = true;
            x = has[x];
        }
        printf("%s\n", tk[1] && tk[2] && tk[3]? "YES": "NO");
    }
    return 0;
}