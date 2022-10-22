#include <bits/stdc++.h>
using namespace std;

set <int> S;
int n;

int main()
{
    scanf("%d", &n);
    while (n--) {
        int a; scanf("%d", &a);
        if (a) S.insert(a);
    }
    printf("%d\n", int(S.size()));
    return 0;
}