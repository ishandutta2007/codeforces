#include <bits/stdc++.h>
using namespace std;

int t;
int a, b;

int gcd(int a, int b) { return a? gcd(b % a, a): b; }

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        printf("%s\n", gcd(a, b) == 1? "Finite": "Infinite");
    }
    return 0;
}