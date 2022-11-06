#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int main() {

    int n;
    scanf("%d", &n);
    if (n % 2 == 1) {
        printf("0\n");
        return 0;
    } else {
        printf("%d\n", (n - 1) / 4 + (((n - 1) % 4) == 0));
    }

    return 0;
}