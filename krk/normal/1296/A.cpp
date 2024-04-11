#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int od = 0, ev = 0;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            if (a % 2) od++;
            else ev++;
        }
        bool res = false;
        if (od && ev) res = true;
        else if (od && n % 2) res = true;
        printf("%s\n", res? "YES": "NO");
    }
    return 0;
}