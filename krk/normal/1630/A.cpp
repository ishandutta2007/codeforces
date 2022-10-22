#include <bits/stdc++.h>
using namespace std;

int T;
int n, k;

void Print(set <int> &S)
{
    for (int i = 0; i < n; i++) if (!S.count(i)) {
        printf("%d %d\n", i, (i ^ (n - 1)));
        S.insert(i);
        S.insert(i ^ (n - 1));
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        if (n <= 4 && k == n - 1) { printf("-1\n"); continue; }
        set <int> S;
        if (k == 0) Print(S);
        else if (k != n - 1) {
            printf("%d %d\n", k, n - 1);
            printf("%d %d\n", (k ^ (n - 1)), 0);
            S.insert(k);
            S.insert(n - 1);
            S.insert((k ^ (n - 1)));
            S.insert(0);
            Print(S);
        } else {
            printf("%d %d\n", n - 2, n - 1);
            printf("1 3\n");
            printf("0 %d\n", (3 ^ (n - 1)));
            S.insert(n - 2);
            S.insert(n - 1);
            S.insert(1);
            S.insert(3);
            S.insert(0);
            S.insert(3 ^ (n - 1));
            Print(S);
        }
    }
    return 0;
}