#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, h, k;
int tab[N];

int main() {

    scanf("%d %d %d", &n, &h, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }

    int freeSpace = h;
    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        if (freeSpace < tab[i]) {
            int additionalMoves = (tab[i] - freeSpace + k - 1) / k;
            ans += additionalMoves;
            freeSpace = min((long long)h, freeSpace + (long long)additionalMoves * k);
        }
        freeSpace -= tab[i];
    }

    ans += (h - freeSpace + k - 1) / k;
    printf("%I64d\n", ans);

    return 0;
}