#include <bits/stdc++.h>

using namespace std;

const int N = 5005, INF = 1e6;

int n, m, mini[N];
int from[N * 4], to[N * 4], cnt[N];

int dist(int w, int u) {
    if (w <= u) return u - w;
    else return u - w + n;
}

int main() {
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        mini[i] = INF;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &from[i], &to[i]);
        from[i]--;
        to[i]--;
        cnt[from[i]]++;
        mini[from[i]] = min(mini[from[i]], dist(from[i], to[i]));
    }
    
    for (int i = 0; i < n; i++) {
        int maxTime = 0;
        for (int j = 0; j < n; j++) {
            if (cnt[(i + j) % n] == 0) continue;
            maxTime = max(maxTime, (cnt[(i + j) % n] - 1) * n + j + mini[(i + j) % n]);
        }
        printf("%d ", maxTime);
    }
    printf("\n");
}