#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int h = 0;
    int ans = 0;
    int ile = 0;
    while (n > 0) {
        h += 2;
        if (h % 3 != 0) {
            n--;
        } else ile++;
        while (ile > 0 && n > 0 && 3 * m < h) {
            n--;
            m++;
            ile--;
        }
    }
    
    printf("%d\n", max(h, 3 * m));
    return 0;
}