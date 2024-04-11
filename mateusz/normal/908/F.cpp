#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

int n, x[N];
char col[N];
int edgeRed[N], edgeBlue[N];

int recentBlue, recentRed;

void addBlue(int i) {
    if (recentBlue != -1) {
        edgeBlue[i] = recentBlue;
    }
    recentBlue = i;
}

void addRed(int i) {
    if (recentRed != -1) {
        edgeRed[i] = recentRed;
    }
    recentRed = i;
}

int main() {
  
    scanf("%d", &n);
    recentBlue = recentRed = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d %c", &x[i], &col[i]);
        edgeRed[i] = edgeBlue[i] = -1;
        if (col[i] == 'G') {
            addBlue(i);
            addRed(i);
        } else if (col[i] == 'B') {
            addBlue(i);
        } else {
            addRed(i);
        }
    }
    
    int lastGreen = -1;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (edgeRed[i] != -1) {
            ans += x[i] - x[edgeRed[i]];
        }
        if (edgeBlue[i] != -1) {
            ans += x[i] - x[edgeBlue[i]];
        }
//         cerr << i << " " << edgeBlue[i] << " " << edgeRed[i] << endl;
        if (col[i] == 'G') {
            if (lastGreen != -1) {
                int maxBlue = 0;
                int maxRed = 0;
                for (int j = lastGreen + 1; j <= i; j++) {
                    if (edgeBlue[j] != -1) {
                        maxBlue = max(maxBlue, x[j] - x[edgeBlue[j]]);
                    }
                    if (edgeRed[j] != -1) {
                        maxRed = max(maxRed, x[j] - x[edgeRed[j]]);
                    }
                }
//                 cerr << i << " " << ans << " " << x[i] - x[lastGreen] << " " << maxRed << " " << maxBlue << endl;
                if (x[i] - x[lastGreen] < maxRed + maxBlue) {
                    ans += x[i] - x[lastGreen] - maxRed - maxBlue;
                }
            }
            lastGreen = i;
        }
    }
    
    printf("%lld\n", ans);
    return 0;
}