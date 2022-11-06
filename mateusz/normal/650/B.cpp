#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int n;
long long a, b, T;
char ori[N];
long long tab[2 * N];
long long timeNeeded[N];

int main() {

    scanf("%d %lld %lld %lld", &n, &a, &b, &T);
    long long begT = T;

    scanf("%s", &ori[1]);

    for (int i = 1; i <= n; i++) {
        tab[i] = (ori[i] == 'w' ? b + 1 : 1);
        tab[i + n] = tab[i];
    }

    int ans = 0;
    for (int i = n; i >= 1; i--) {
        timeNeeded[i] = timeNeeded[i + 1] + a + tab[i];

    }

    for (int i = n + 1; i <= 2 * n; i++) {
        T -= tab[i];
        if (T < 0) break;
        long long remainingTime = T - (i - n - 1) * a;
        int low = 1;
        int high = 2 * n - i;
        int res = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (timeNeeded[n + 1 - mid] <= remainingTime) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        ans = max(ans, i - n + res);
        T -= a;
    }

    reverse(tab + 2, tab + 1 + n);

    for (int i = 1; i <= n; i++) {
        tab[i + n] = tab[i];
    }

    T = begT;
    for (int i = n; i >= 1; i--) {
        timeNeeded[i] = timeNeeded[i + 1] + a + tab[i];
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        T -= tab[i];
        if (T < 0) break;
        long long remainingTime = T - (i - n - 1) * a;
        int low = 1;
        int high = 2 * n - i;
        int res = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (timeNeeded[n + 1 - mid] <= remainingTime) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        ans = max(ans, i - n + res);
        T -= a;
    }


    printf("%d\n", ans);

    return 0;
}