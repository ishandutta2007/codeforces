#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7, N = 1000005;

int p, k;
bool vis[N];
int cnt[N], res[N];

int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    return (long long)power((long long)a * a % M, b / 2) * (b % 2 == 1 ? a : 1) % M;
}

int main() {

    scanf("%d %d", &p, &k);
    if (k == 0) {
        printf("%d\n", power(p, p - 1));
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < p; i++) {
        int w = i;
        if (!vis[i]) {
            int l = 0;
            do {
                l++;
                vis[i] = true;
                i = (long long)i * k % p;
            } while (vis[i] == false);
            cnt[l]++;
        }
        i = w;
    }

    for (int i = 1; i <= p; i++) {
        for (int j = i; j <= p; j += i) {
            res[j] = res[j] + i * cnt[i];
        }
        if (cnt[i] > 0)
        ans = (long long)ans * power(res[i], cnt[i]) % M;
    }

    printf("%d\n", ans);

    return 0;
}