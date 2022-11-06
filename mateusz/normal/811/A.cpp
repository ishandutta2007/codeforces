#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = 1;; i++) {
        if (a < i) {
            if (i % 2 == 1) {
                printf("Vladik\n");
            } else {
                printf("Valera\n");
            }
            break;
        }
        a -= i;
        swap(a, b);
    }
    return 0;
}