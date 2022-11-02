#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int r, h, ans;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &r, &h);
    ans += 2 * (h / r);
    h %= r;
    if (ll(h) * h * 4 >= ll(r) * r * 3) ans += 3;
    else if (2 * h >= r) ans += 2;
    else ans++;
    printf("%d\n", ans);
}