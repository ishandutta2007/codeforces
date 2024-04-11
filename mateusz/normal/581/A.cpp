#include <bits/stdc++.h>

using namespace std;

int main() {

    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d ", min(a, b));

    b = max(a, b) - min(a, b);
    printf("%d\n", b / 2);

    return 0;
}