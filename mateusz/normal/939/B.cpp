#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
long long a[N];
long long m;

int main() {
    
    scanf("%lld %d", &m, &n);
 
    long long r = m;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        r = min(r, m % a[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        if (r == m % a[i]) {
            printf("%d %lld\n", i, m / a[i]);
            return 0;
        }
    }
    
    return 0;
}