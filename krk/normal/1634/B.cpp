#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n, x;
ll y;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %I64d", &n, &x, &y);
        int A = x % 2;
        for (int i = 0; i < n; i++) {
            int b; scanf("%d", &b);
            if (b % 2) A = 1 - A;
        }
        if (A == y % 2) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}