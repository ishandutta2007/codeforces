#include <bits/stdc++.h>
using namespace std;

int n, t;
int best = 1000000000, bi = -1;

int main()
{
    scanf("%d %d", &n, &t);
    for (int i = 1; i <= n; i++) {
        int s, d; scanf("%d %d", &s, &d);
        if (s < t)
            s = s + ((t - s - 1) / d + 1) * d;
        if (s < best) { best = s; bi = i; }
    }
    printf("%d\n", bi);
    return 0;
}