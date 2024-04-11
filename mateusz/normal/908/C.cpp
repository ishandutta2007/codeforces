#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, r;
int x[N];
long double y[N];

int main() {
  
    scanf("%d %d", &n, &r);
    r *= 2;
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        long double myY = r / 2;
        for (int j = 1; j < i; j++) {
            if (abs(x[i] - x[j]) <= r) {
                myY = max(myY, y[j] + sqrt(r*r - abs(x[i] - x[j]) * abs(x[i] - x[j])));
            }
        }
        y[i] = myY;
        printf("%.10Lf ", myY);
    }
  
    return 0;
}