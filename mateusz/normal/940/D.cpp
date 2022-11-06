#include <bits/stdc++.h>

using namespace std;

const int N = 1000005, INF = 1e9;

int n;
int a[N], b[N], bb[N];
char s[N];

int prefSum[N];



int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    scanf("%s", &s[1]);
    for (int i = 1; i <= n; i++) {
        b[i] = s[i] - '0';
        prefSum[i] = prefSum[i - 1] + b[i];
    }
    
    int minL = -INF;
    int maxR = INF;
    for (int i = 5; i <= n; i++) {
        if (prefSum[i - 1] - prefSum[i - 5] == 0 && b[i] == 1) {
            for (int j = i; j >= i - 4; j--) {
                minL = max(minL, a[j] + 1);
            }
        }
        if (prefSum[i - 1] - prefSum[i - 5] == 4 && b[i] == 0) {
            for (int j = i; j >= i - 4; j--) {
                maxR = min(maxR, a[j] - 1);
            }
        }
    }
    
    printf("%d %d\n", minL, maxR);
    
    
    return 0;
}