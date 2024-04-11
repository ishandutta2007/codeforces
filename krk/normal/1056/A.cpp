#include <bits/stdc++.h>
using namespace std;

const int Maxm = 101;

int t;
int was[Maxm];

int main()
{
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n; scanf("%d", &n);
        while (n--) {
            int a; scanf("%d", &a);
            was[a]++;
        }
    }
    bool pr = false;
    for (int i = 1; i < Maxm; i++) if (was[i] >= t) {
        if (pr) printf(" ");
        else pr = true;
        printf("%d", i);
    }
    printf("\n");
    return 0;
}