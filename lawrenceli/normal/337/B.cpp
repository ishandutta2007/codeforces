#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if (a<b) swap(a, b);
    if (b==0) return a;
    return gcd(b, a-b);
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a*d>b*c) {
        swap(a, b); swap(c, d);
    }
    int p = b*c - a*d, q = b*c;
    int g = gcd(p, q);
    printf("%d/%d\n", p/g, q/g);
}