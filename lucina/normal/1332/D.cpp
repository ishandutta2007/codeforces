#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int main () {
    int add = 1 << 17;
    int k;
    scanf("%d", &k);
    int p = k + add;

    printf("3 4\n");
    printf("%d %d %d %d\n", p, p, k, add);
    printf("%d %d %d %d\n", add, add, p, add);
    printf("%d %d %d %d\n", add, add, k, k);
}
/*
    Good Luck
        *Lucina
*/