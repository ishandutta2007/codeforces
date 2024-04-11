#include <bits/stdc++.h>
using namespace std;

int T;
int sum;

int main()
{
    scanf("%d", &T);
    while (T--) {
        sum = 0;
        for (int i = 0; i < 4; i++) {
            int a; scanf("%d", &a);
            sum += a;
        }
        if (sum == 0) printf("0\n");
        else if (sum == 4) printf("2\n");
        else printf("1\n");
    }
    return 0;
}