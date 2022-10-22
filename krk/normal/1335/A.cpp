#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int lef = 1, rig = (n - 1) / 2;
        printf("%d\n", rig - lef + 1);
    }
    return 0;
}