#include <bits/stdc++.h>

using namespace std;

int k;

int sumDigits(int w) {
    int sum = 0;
    while (w >= 1) {
        sum += w % 10;
        w /= 10;
    }
    return sum;
}

int main() {
    
    scanf("%d", &k);
    
    int cnt = 0;
    for (int i = 1;; i++) {
        if (sumDigits(i) == 10) {
            cnt++;
            if (cnt == k) {
                printf("%d\n", i);
                return 0;
            }
        } 
    }
    
    return 0;
}