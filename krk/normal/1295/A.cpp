#include <bits/stdc++.h>
using namespace std;

int t;
int n;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (n % 2) { printf("7"); n -= 3; }
        if (n > 0) printf("%s", string(n / 2, '1').c_str());
        printf("\n");
    }
    return 0;
}