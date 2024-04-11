#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        int lef = (n - 1) / 2;
        int rig = n / 2;
        while (lef > 0 && rig + 1 < n && str[lef - 1] == str[lef]) {
            lef--;
            rig++;
        }
        printf("%d\n", rig - lef + 1);
    }
    return 0;
}