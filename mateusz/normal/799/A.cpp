#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int main() {
  
    int n, t, k, d;
    scanf("%d %d %d %d", &n, &t, &k, &d);
    
    int timeOneOven = ((n + k - 1) / k) * t;
    timeOneOven--;
    
    int twoOvens = timeOneOven / t * k + max(0, (timeOneOven - d)) / t * k;
    if (twoOvens >= n) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}