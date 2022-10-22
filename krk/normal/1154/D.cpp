#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, b, a;
int curb, cura;

int main()
{
    cin >> n >> b >> a;
    curb = b; cura = a;
    for (int i = 1; i <= n; i++) {
        int s; scanf("%d", &s);
        if (s == 1)
            if (cura == a) cura--;
            else if (curb > 0) { curb--; cura++; }
            else if (cura > 0) cura--;
            else { printf("%d\n", i - 1); return 0; }
        else if (cura > 0) cura--;
             else if (curb > 0) curb--;
             else { printf("%d\n", i - 1); return 0; }
    }
    printf("%d\n", n);
    return 0;
}