#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        if (n <= 30) { printf("NO\n"); continue; }
        int a = 6, b = 10, c = 14;
        int d = n - a - b - c;
        if (d == a || d == b || d == c) {
            c = 15;
            d--;
        }
        printf("YES\n");
        printf("%d %d %d %d\n", a, b, c, d);
    }
    return 0;
}