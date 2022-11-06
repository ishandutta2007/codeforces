#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " " << (x) << endl;
using namespace std;

const int N = 1000005;

int n, k;
int c[N];
int dp[2000];
int factors[100], fSize;
int product[100];
int cnt[N];
bool good[200];

int main() {

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        cnt[c[i]]++;
    }
    int w = k;
    for (int i = 2; i <= k; i++) {
        if (w % i == 0) {
            factors[fSize++] = i;
            product[fSize - 1] = 1;
        }
        while (w % i == 0) {
            product[fSize - 1] *= i;
            w /= i;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < fSize; j++) {
            if (c[i] % product[j] == 0) {
                good[j] = true;
            }
        }
    }

    for (int j = 0; j < fSize; j++) {
        if (good[j] == false) {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
    return 0;

    dp[0] = true;
    for (int i = 1; i < (1 << fSize); i++) {
        for (int j = 1; j <= i; j++) {
            if ((i & j) != j) {
                continue;
            }
            int sc = 1;
            for (int k = 0; k < fSize; k++) {
                if ((j & (1 << k)) == (1 << k)) {
                    sc *= product[k];
                }
            }
            if (cnt[sc] && dp[i ^ j]) {
                dp[i] = true;
                break;
            }
        }
    }

    printf(dp[(1 << fSize) - 1] ? "Yes\n" : "No\n");

    return 0;
}