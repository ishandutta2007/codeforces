#include <bits/stdc++.h>

using namespace std;
const int N = 1000005;
int m, h1, h2, a1, a2, x1, x2, yy1, y2;
bool odw[N];
int main() {
    scanf("%d", &m);
    scanf("%d %d", &h1, &a1);
    scanf("%d %d", &x1, &yy1);
    scanf("%d %d %d %d", &h2, &a2, &x2, &y2);
    if(h1 == x2 && h2 == a2) {
        printf("0\n");
        return 0;
    }
    int operations = 0;
    while(h1 != a1 && odw[h1] == false) {
        odw[h1] = true;
        h1 = ((long long)h1 * x1 % m + yy1) % m;
        operations++;
    }
    if(h1 != a1) {
        printf("-1\n");
        return 0;
    }
    for(int i = 0; i < m; i++) {
        odw[i] = false;
    }
    long long x0 = operations;
    operations = 0;
    
    while(h2 != a2 && odw[h2] == false) {
        odw[h2] = true;
        h2 = ((long long)h2 * x2 % m + y2) % m;
        operations++;
    }
    if(h2 != a2) {
        printf("-1\n");
        return 0;
    }
    for(int i = 0; i < m; i++) {
        odw[i] = false;
    }
    long long y0 = operations;
    operations = 0;
    if(x0 == y0){
        printf("%I64d\n", x0);
        return 0;
    }
    
    do {
        operations++;
        odw[h1] = true;
        h1 = ((long long)h1 * x1 % m + yy1) % m;
    } while(h1 != a1 && odw[h1] == false);
    if(h1 != a1) {
        printf("-1\n");
        return 0;
    }
    for(int i = 0; i < m; i++) {
        odw[i] = false;
    }
    long long A = operations;
    operations = 0;
    if(x0 + A == y0){
        printf("%I64d\n", x0 + A);
        return 0;
    }
    
    do {
        operations++;
        odw[h2] = true;
        h2 = ((long long)h2 * x2 % m + y2) % m;
    } while(h2 != a2 && odw[h2] == false);
     
    if(h2 != a2) {
        printf("-1\n");
        return 0;
    }
    
  
    for(int i = 0; i < m; i++) {
        odw[i] = false;
    }
    long long B = operations;
    while(x0 < y0) {
        x0 += A;
    }
    long long dist = (x0 - y0);
    while(dist != 0 && odw[dist] == false) {
        odw[dist] = true;
        while(y0 < x0) {
            y0 += B;
        }
        while(x0 < y0) {
            x0 += A;
        }
        dist = x0 - y0;
    }
    if(dist == 0) {
        printf("%I64d\n", x0);
    } else {
        printf("-1\n");
    }
    return 0;
}