#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

pair<int, int> col[N], row[N];
int n, m, k, what, nr, color;

int main() {

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d %d %d", &what, &nr, &color);
        if (what == 1) {
            row[nr] = make_pair(color, i);
        } else {
            col[nr] = make_pair(color, i);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (row[i].second > col[j].second) {
                printf("%d ", row[i].first);
            } else {
                printf("%d ", col[j].first);
            }
        }
        printf("\n");
    }
    return 0;
}