#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N, K;
int X[200001];
int S[200001];
int M[200001];

void loop() {
    scanf("%d%d", &N, &K);
    rep(i, N) scanf("%d", &X[i]);
    rep(i, N) scanf("%d", &X[N]);
    X[N] = 2000000000;
    sort(X, X + N);
    for (int p = 0, q = 0; q < N; q++) {
        while (X[p] < X[q] - K) p++;
        S[q] = q - p + 1;
    }
    M[0] = 0;
    rep(i, N) M[i + 1] = max(M[i], S[i]);
    int ans = 0;
    rep(i, N) {
        int p = i - S[i] + 1;
        ans = max(ans, S[i] + M[p]);
    }
    printf("%d\n", ans);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) loop();

    return 0;
}