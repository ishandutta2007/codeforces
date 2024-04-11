#include <bits/stdc++.h>
using namespace std;

int t;
int h, m;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &h, &m);
        int res = 0;
        res += 60 - m; h++;
        res += (24 - h) * 60;
        printf("%d\n", res);
    }
    return 0;
}