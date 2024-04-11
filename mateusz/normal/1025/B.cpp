#include <bits/stdc++.h>

using namespace std;

const int N = 150005;

int a[N], b[N];

int main() {
    
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    
    set<int> divs;
    int w = a[1];
    for (int i = 2; i * i <= w; i++) {
        while (w % i == 0) {
            divs.insert(i);
            w /= i;
        }
    }
    if (w > 1) {
        divs.insert(w);
    }
    w = b[1];
    for (int i = 2; i * i <= w; i++) {
        while (w % i == 0) {
            divs.insert(i);
            w /= i;
        }
    }
    if (w > 1) {
        divs.insert(w);
    }
    for (int d : divs) {
        bool good = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] % d != 0 && b[i] % d != 0) {
                good = false;
                break;
            }
        }
        if (good) {
            printf("%d\n", d);
            return 0;
        }
    }
    
    printf("-1\n");
    
    return 0;
}