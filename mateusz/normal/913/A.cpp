#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, m;
    scanf("%d %d", &n, &m);
    

    int mod = 1;
    int i = 0;
    while (mod <= m && i < n) {
        mod *= 2;
        i++;
    }
    
    printf("%d\n", m % mod);
    
    return 0;
}