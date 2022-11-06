#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int n, k;
int tab[N];

int main() {

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        if (i > 1 && tab[i] != tab[i - 1]) {
        }
    }

    sort(tab + 1, tab + 1 + n);

    int low = tab[1];
    int high = tab[n];
    int res = 1;
    while (low <= high) {
        int mid = ((long long)low + high) / 2;
        long long cost = 0;
        for (int i = 1; i <= n; i++) {
            if (tab[i] >= mid) {
                break;
            }
            cost += mid - tab[i];
        }
        if (cost > k) {
            high = mid - 1;
        } else {
            low = mid + 1;
            res = mid;
        }
    }

    low = tab[1];
    high = tab[n];
    int res2 = tab[n];
    while (low <= high) {
        int mid = ((long long)low + high) / 2;
        long long cost = 0;
        for (int i = n; i >= 1; i--) {
            if (tab[i] <= mid) {
                break;
            }
            cost += tab[i] - mid;
        }
        if (cost > k) {
            low = mid + 1;
        } else {
            high = mid - 1;
            res2 = mid;
        }
    }

    if (res2 <= res) {
        int low = res2;
        int high = res;
        while (low <= high) {
            int mid = ((long long)low + high) / 2;
            long long c1 = 0, c2 = 0;
            for (int i = 1; i <= n; i++) {
                if (tab[i] <= mid) {
                    c1 += mid - tab[i];
                } else {
                    c2 += tab[i] - mid;
                }
            }
            if (c1 == c2) {
                printf("0\n");
                return 0;
            } else if (c1 > c2) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }

    printf("%d\n", max(1, res2 - res));

    return 0;
}