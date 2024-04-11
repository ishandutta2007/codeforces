#include <bits/stdc++.h>
using namespace std;

int T;
int a, b, c;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a, &b, &c);
        printf("%d %d %d\n", max(0, max(b, c) + 1 - a), max(0, max(a, c) + 1 - b), max(0, max(a, b) + 1 - c));
    }
    return 0;
}