#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;
int B[2][2];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        bool was = false;
        for (int i = 0; i < n; i++) {
            for (int r = 0; r < 2; r++)
                for (int c = 0; c < 2; c++)
                    scanf("%d", &B[r][c]);
            if (B[0][1] == B[1][0]) was = true;
        }
        if (m % 2) was = false;
        printf("%s\n", was? "YES": "NO");
    }
    return 0;
}