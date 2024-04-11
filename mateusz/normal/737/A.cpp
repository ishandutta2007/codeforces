#include <bits/stdc++.h>

using namespace std;

const int N = 200005, INF = 2e9;

int n, k, s, t;
int cost[N], capacity[N], station[N];

bool enough(int c) {
    int travelTime = 0;
    int last = 0;
    for (int i = 1; i <= k; i++) {
        int d = station[i] - last;
        if (c < d) {
            return false;
        }
        int acc = min(d, c - d);
        travelTime += acc + 2 * (d - acc);
        last = station[i];
    }
    int d = s - last;
    if (c < d) {
        return false;
    }
    int acc = min(d, c - d);
    travelTime += acc + 2 * (d - acc);
    return travelTime <= t;
}

int main() {

    scanf("%d %d %d %d", &n, &k, &s, &t);

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &cost[i], &capacity[i]);
    }

    for (int i = 1; i <= k; i++) {
        scanf("%d", &station[i]);
    }

    sort(station + 1, station + 1 + k);

    int low = 1;
    int high = 2e9;
    int res = high;
    while (low <= high) {
        int mid = ((long long)low + high) / 2;
        if (enough(mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    int best = INF;
    for (int i = 1; i <= n; i++) {
        if (capacity[i] >= res) {
            best = min(best, cost[i]);
        }
    }

    if (best == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", best);
    }

    return 0;
}