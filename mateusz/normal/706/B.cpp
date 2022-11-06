#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m, q;
int tab[N];

int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }

    sort(tab + 1, tab + 1 + n);

    scanf("%d", &q);

    while (q--) {
        scanf("%d", &m);
        int low = 1;
        int high = n;
        int res = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (tab[mid] <= m) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        printf("%d\n", res);
    }

    return 0;
}