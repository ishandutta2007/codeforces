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
        int lef = 0, rig = 0;
        while (lef < n && str[lef] == '0') lef++;
        while (rig < n && str[n - 1 - rig] == '1') rig++;
        if (lef > 0) printf("%s", string(lef, '0').c_str());
        if (lef + rig < n) printf("0");
        if (rig > 0) printf("%s", string(rig, '1').c_str());
        printf("\n");
    }
    return 0;
}