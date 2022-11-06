#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, k;
int col[N];
int used[1005];
int zap[1005];
int ile[1005];

int main() {

    scanf("%d %d", &n, &k);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &col[i]);
    }
    
    for (int i = 0; i < 256; i++) {
        used[i] = -1;
    }
    
    for (int i = 1; i <= n; i++) {
        int w = col[i];
        int cnt = 1;
        if (used[w] != -1) {
            printf("%d ", used[w]);
            continue;
        }
        while (cnt < k && w > 0 && used[w - 1] == -1) {
            w--;
            cnt++;
        } 
        if (w > 0 && used[w - 1] != -1 && w - 1 + zap[w - 1] >= col[i] && ile[w - 1] + col[i] - w + 1 <= k) {
            for (int j = w; j <= col[i]; j++) {
                used[j] = used[j - 1];
                zap[j] = zap[j - 1] - 1;
                ile[j] = ile[j - 1] + 1;
            }
        } else {
            used[w] = w;
            zap[w] = k;
            ile[w] = 1;
            for (int j = w + 1; j <= col[i]; j++) {
                used[j] = used[j - 1];
                zap[j] = zap[j - 1] - 1;
                ile[j] = ile[j - 1] + 1;
            }
        }
        
        printf("%d ", used[col[i]]);
    }
    
    
    return 0;
}