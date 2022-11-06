#include <bits/stdc++.h>

using namespace std;

const int N = 200005, M = 1e9 + 7;

int m;
int x;
int cnt[N];

int pot(int a, int k) {
    if (k == 0) return 1;
    return (long long)pot((long long)a * a % M, k / 2) * (k % 2 ? a : 1) % M;
}

int main() {

    scanf("%d", &m);

    for (int i = 1; i <= m; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }

    int ans = 1;
    int ile = 1;
    for (int i = 2; i <= 200000; i++) {
        int curAns = ans;
        int w = 1;
        for (int j = 1; j <= cnt[i]; j++) {
            w = (long long)w * i % M;
            ans = (long long)ans * curAns % M * (long long)pot(w, ile) % M;
        }
        ile = (long long)ile * (cnt[i] + 1) % (M - 1);
    }

    printf("%d\n", ans);

    return 0;
}