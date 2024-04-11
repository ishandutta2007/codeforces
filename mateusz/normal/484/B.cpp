#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 2000005;
int n, tab[N], zlicz[N], pref[N];
int main() {
    scanf("%d", &n);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        mx = max(mx, tab[i]);
        zlicz[tab[i]] = 1;
    }
    for (int i = 1; i <= 2 * mx; i++) {
        if (zlicz[i] > 0)
            pref[i + 1] = i;
        else
            pref[i + 1] = pref[i];
    }
    int ans = 0;
    for (int i = 1; i <= mx; i++) {
        if (zlicz[i] == 0) continue;
        for (int j = i; j <= 2 * mx; j += i) {
            if (pref[j] >= i)
                ans = max(ans, pref[j] % i);
        }
    }
    printf("%d", ans);  
    return 0;
}