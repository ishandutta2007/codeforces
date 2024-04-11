#include <bits/stdc++.h>

using namespace std;

const int A = 1234567, B = 123456, C = 1234;

int n;

int main() {

    scanf("%d", &n);

    for (int a = 0; a * A <= n; a++) {
        for (int b = 0; a * A + b * B <= n; b++) {
            int remaining = n - a * A - b * B;
            if (remaining % C == 0) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");

    return 0;
}