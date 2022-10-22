#include <bits/stdc++.h>
using namespace std;

int n;
int c, sum;

int main()
{
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &c, &sum);
        int a = sum / c;
        int b = sum / c + 1;
        int cntb = sum % c;
        int cnta = c - cntb;
        printf("%d\n", cnta * a * a + cntb * b * b);
    }
    return 0;
}