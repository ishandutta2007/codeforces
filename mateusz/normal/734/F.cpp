#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n;
int a[N], b[N], c[N];
int cnt[40];

int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }

    int low = b[1];
    int high = c[1];
    int res = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        bool tooHigh = false;
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            int val = -(mid - b[i] - c[i]);
            if (val < 0) {
                tooHigh = true;
                break;
            } else {
                sum += val;
            }
        }
        if (tooHigh || sum < (long long)n * mid) {
            high = mid - 1;
        } else {
            if (sum == (long long)n * mid) {
                res = mid;
                break;
            } else {
                low = mid + 1;
            }
        }
    }

    if (res == -1) {
        printf("-1\n");
    } else {
        for (int i = 1; i <= n; i++) {
            a[i] = -(res - b[i] - c[i]) / n;
            for (int j = 0; j < 30; j++) {
                if (a[i] & (1 << j)) {
                    cnt[j]++;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            long long _and = 0;
            long long _or = 0;
            for (int j = 0; j < 30; j++) {
                if (a[i] & (1 << j)) {
                    _and += (long long)(1 << j) * cnt[j];
                    _or += (long long)(1 << j) * n;
                } else {
                    _or += (long long)(1 << j) * cnt[j];
                }
            }
            if (_and != b[i] || _or != c[i]) {
                printf("-1\n");
                return 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
    }
    return 0;
}