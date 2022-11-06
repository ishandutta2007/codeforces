#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, d;
pair<int, int> tab[N];

int main() {

    scanf("%d %d", &n, &d);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &tab[i].first, &tab[i].second);
    }

    sort(tab + 1, tab + 1 + n);

    int high = 1;
    long long sum = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        high = max(high, i);
        if (high == i) {
            sum = tab[i].second;
        }
        while (high + 1 <= n && tab[high + 1].first - tab[i].first < d) {
            high++;
            sum += tab[high].second;
        }
        ans = max(ans, sum);
        sum -= tab[i].second;
    }

    printf("%I64d\n", ans);

    return 0;
}