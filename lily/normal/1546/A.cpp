#include <bits/stdc++.h>
using namespace std;

int a[105], b[105];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int suma = 0, sumb = 0;
        for (int i = 0; i < n; i++) scanf("%d", a + i), suma += a[i];
        for (int i = 0; i < n; i++) scanf("%d", b + i), sumb += b[i];
        if (suma != sumb) {
            puts("-1");
        } else {
            vector < pair <int, int> > ans;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    while (a[i] > b[i] && a[j] < b[j]) {
                        a[i]--;
                        a[j]++;
                        ans.push_back({i, j});
                    }
                }
            printf("%d\n", int(ans.size()));
            for (auto v : ans) {
                printf("%d %d\n", v.first +1, v.second +1);
            }
        }
    }
}