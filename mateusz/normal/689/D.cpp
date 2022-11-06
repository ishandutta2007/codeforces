#include <bits/stdc++.h>

using namespace std;

const int N = 200005, LOG = 19;

int RMQA[LOG][2 * N], RMQB[LOG][2 * N];
int getLog[N];

int queryA(int a, int b) {
    int l = b - a + 1;
    int x = getLog[l];
    return max(RMQA[x][a], RMQA[x][b - (1 << x) + 1]);
}

int queryB(int a, int b) {
    int l = b - a + 1;
    int x = getLog[l];
    return min(RMQB[x][a], RMQB[x][b - (1 << x) + 1]);
}

int n, a[N], b[N];

int find(int pos, int maxValue) {
    int low = 1;
    int high = n - pos + 1;
    int ret = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (queryA(pos, pos + mid - 1) - queryB(pos, pos + mid - 1) <= maxValue) {
            ret = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ret;
}

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    int x = 1;
    getLog[1] = 0;
    for (int i = 2; i <= n; i++) {
        if ((1 << (x + 1)) == i) {
            x++;
        }
        getLog[i] = x;
    }
    for (int i = 1; i <= n; i++) {
        RMQA[0][i] = a[i];
        RMQB[0][i] = b[i];
    }

    for (int l = 1; l <= 18; l++) {
        for (int i = 1; i <= n; i++) {
            RMQA[l][i] = max(RMQA[l - 1][i], RMQA[l - 1][i + (1 << (l - 1))]);
            RMQB[l][i] = min(RMQB[l - 1][i], RMQB[l - 1][i + (1 << (l - 1))]);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int start = find(i, -1);
        int finish = find(i, 0);
        ans += finish - start;
    }

    printf("%I64d\n", ans);

    return 0;
}