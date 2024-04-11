#include <bits/stdc++.h>
using namespace std;

int n;
int od, ev;

int main()
{
    scanf("%d", &n);
    while (n--) {
        int a; scanf("%d", &a);
        if (a % 2) od++;
        else ev++;
    }
    printf("%d\n", min(od, ev));
    return 0;
}