#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

int n, m, l, r, x;
int p[N];

int main() {
    
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    
    while (m--) {
        scanf("%d %d %d", &l, &r, &x);
        int smaller = 0;
        for (int i = l; i <= r; i++) {
            if (p[i] < p[x]) {
                smaller++;
            }
        }
        if (l + smaller == x) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    
    return 0;
}