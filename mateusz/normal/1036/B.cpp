#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int main() {

    int q;
    scanf("%d", &q);
    
    while (q--) {
        long long n, m, k;
        scanf("%lld %lld %lld", &n, &m, &k);
        if (k < max(n, m)) {
            printf("-1\n");
            continue;
        }
        long long mn = min(n, m);
        long long diagonals = mn;
        k -= mn;
        n -= mn;
        m -= mn;
        if (n == 0) {
            swap(n, m);
        }
        
        diagonals += n;
        k -= n;
        if (n % 2 == 1) {
            diagonals--;
        }
        if (k % 2 == 0) {
            diagonals += k;
        } else {
            diagonals += k - 1;
            if (n % 2) {
                diagonals++;
            } else {
                if (diagonals > 0) {
                    diagonals--;
                } else {
                    printf("-1\n");
                    continue;
                }
            }
        }
        printf("%lld\n", diagonals);
        
    }
    
    return 0;
}