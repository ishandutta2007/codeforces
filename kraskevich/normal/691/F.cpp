#include <bits/stdc++.h>

using namespace std;

const int N = (int) 3e6 + 10;

int cnt[N];
int pref[N];
long long f[N];
long long add[N + 1];
long long self[N];

void prec() {
    for (int i = 1; i < N; i++)
        self[i] = cnt[i] * 1ll * (cnt[i] - 1) + self[i - 1];
    for (int i = 1; i < N; i++) {
        for (int d = 1; d * i < N; d++) {
            int minP = d * i;
            int maxP = min(N, i * (d + 1));
            long long delta = cnt[i] * 1ll * pref[d];
            if (d >= i) {
                delta = cnt[i] * (pref[d] - cnt[i]);
            }
            add[minP] += delta;
            add[maxP] -= delta;
        }
    }
    long long sum = 0;
    int x = 0;
    for (int i = 1; i < N; i++) {
        while (x * x <= i)
            x++;
        x--;
        sum += add[i];
        f[i] = sum + self[x];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        cnt[a]++;
    }
    for (int i = 1; i < N; i++)
        pref[i] = pref[i - 1] + cnt[i];
    prec();
    long long tot = n * 1ll * (n - 1);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int p;
        scanf("%d", &p);
        p--;
        printf("%I64d\n", tot - f[p]);   
    }
    return 0;
}