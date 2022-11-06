#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int main() {

    int n, ansA = 0, ansB = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x > y) {
            ansA++;
        }
        if (x < y) {
            ansB++;
        }
    }

    if (ansA == ansB) {
        printf("Friendship is magic!^^\n");
    } else if (ansA > ansB) {
        printf("Mishka\n");
    } else {
        printf("Chris\n");
    }

    return 0;
}