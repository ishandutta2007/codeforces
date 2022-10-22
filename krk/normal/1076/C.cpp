#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int T;
int d;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &d);
        if (d * d - 4 * d < 0) {
            printf("N\n");
            continue;
        }
        ld D = d * d - 4 * d;
        ld a = (d - sqrt(D)) / 2.0l;
        ld b = d - a;
        cout << "Y " << fixed << setprecision(10) << a << " " << fixed << setprecision(10) << b << "\n";
    }
    return 0;
}