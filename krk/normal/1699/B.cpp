#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int val = (i + j) % 2;
                if ((i / 2 + j / 2) % 2) val = 1 - val;
                printf("%d%c", val, j + 1 < m? ' ': '\n');
            }
    }
    return 0;
}