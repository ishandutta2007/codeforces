#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int p[Maxn], c[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d %d", &p[i], &c[i]);
        int curp = 0, curc = 0;
        bool ok = true;
        for (int i = 0; i < n && ok; i++) {
            int deltp = p[i] - curp, deltc = c[i] - curc;
            if (deltp < 0 || deltc < 0 || deltp < deltc) ok = false;
            curp = p[i]; curc = c[i];
        }
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}