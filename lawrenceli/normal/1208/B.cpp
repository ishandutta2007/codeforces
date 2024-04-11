#include <bits/stdc++.h>

using namespace std;

const int maxn = 2005;

int n, a[maxn];

map<int, int> mp;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int ans = 1000000;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        mp.clear();
        for (int j = 0; j < n; j++) {
            mp[a[j]]++;
            if (mp[a[j]] == 2) cnt++;
        }

        for (int j = i; j <= n; j++) {
            if (cnt == 0) {
                ans = min(ans, j - i);
                break;
            }

            mp[a[j]] -= 1;
            if (mp[a[j]] == 1) cnt--;
        }
    }

    printf("%d\n", ans);
}