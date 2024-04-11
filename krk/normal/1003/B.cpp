#include <bits/stdc++.h>
using namespace std;

int a, b, x;

int main()
{
    cin >> a >> b >> x;
    char ca = '0', cb = '1';
    if (a < b) swap(a, b), swap(ca, cb);
    while (x > 1) {
        printf("%c", ca); a--;
        swap(a, b);
        swap(ca, cb);
        x--;
    }
    while (a--) printf("%c", ca);
    while (b--) printf("%c", cb);
    printf("\n");
    return 0;
}