#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int tab[N];
int n, m, c;

int main() {
    
    scanf("%d %d %d", &n, &m, &c);
    
    int low = 0;
    int high = n + 1;
    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        if (x > c / 2) {
            int pos = n;
            while (pos >= high && tab[pos] >= x) {
                pos--;
            }
            tab[pos] = x;
            high = min(pos, high);
            printf("%d\n", pos);
            fflush(stdout);
        } else {
            int pos = 1;
            while (pos <= low && tab[pos] <= x) {
                pos++;
            }
            tab[pos] = x;
            low = max(low, pos);
            printf("%d\n", pos);
            fflush(stdout);
        }
        if (low == high - 1) {
            return 0;
        }
    }
    
    return 0;
}