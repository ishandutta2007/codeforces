#include <bits/stdc++.h>
using namespace std;

int T;
int n;

void First()
{
    printf("Ashishgup\n");
}

void Second()
{
    printf("FastestFinger\n");
}

bool Prime(int n)
{
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n == 1) { Second(); continue; }
        if (n % 2 == 1) { First(); continue; }
        int twos = 0;
        while (n % 2 == 0) {
            n /= 2;
            twos++;
        }
        if (twos == 1) {
            if (Prime(n)) Second();
            else First();
            continue;
        }
        if (n == 1) Second();
        else First();
    }
    return 0;
}