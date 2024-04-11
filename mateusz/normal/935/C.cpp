#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int r, xx1, yy1, x2, y2;
    scanf("%d %d %d %d %d", &r, &xx1, &yy1, &x2, &y2);
    
    if (xx1 == x2 && yy1 == y2) {
        printf("%lf %lf %lf\n", xx1 + (double)r/2, (double)yy1, (double)r/2);
        return 0;
    }
    
    double x = x2 - xx1;
    double y = y2 - yy1;
    
    double len = sqrt(x * x + y * y);
    
    if (len > r) {
        printf("%d %d %d\n", xx1, yy1, r);
        return 0;
    }
    
    double xd = (len + r) / 2;
    
    double newX = x - x*xd/len;
    double newY = y - y*xd/len;
    
    printf("%.10lf %.10lf %.10lf\n", newX + xx1, newY + yy1, xd);
    
    return 0;
}