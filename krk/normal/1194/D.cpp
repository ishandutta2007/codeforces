#include <bits/stdc++.h>
using namespace std;

int t;
int n, k;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        if (k % 3)
            if (n % 3 == 0) printf("Bob\n");
            else printf("Alice\n");
        else {
            n %= (k + 1);
            if (n % 3 == 0 && n < k) printf("Bob\n");
            else printf("Alice\n");
        }
    }
    return 0;
}