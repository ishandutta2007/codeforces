#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int twos = 0, threes = 0;
        while (n % 2 == 0) { n /= 2; twos++; }
        while (n % 3 == 0) { n /= 3; threes++; }
        if (n != 1 || twos > threes) printf("-1\n");
        else printf("%d\n", threes - twos + threes);
    }
    return 0;
}