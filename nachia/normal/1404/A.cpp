#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N, K;
char S[300001];
int C[300000];

void loop() {
    scanf("%d%d", &N, &K);
    scanf(" %s", S);
    rep(i, K) C[i] = -1;
    bool ok = true;
    rep(i, N) {
        if (S[i] == '0') {
            if (C[i % K] == 1) ok = false;
            C[i % K] = 0;
        }
        if (S[i] == '1') {
            if (C[i % K] == 0) ok = false;
            C[i % K] = 1;
        }
    }
    int X[2] = {};
    rep(i, K) {
        if (C[i] != -1) X[C[i]]++;
    }
    if (X[0] > K / 2) ok = false;
    if (X[1] > K / 2) ok = false;
    printf(ok ? "YES\n" : "NO\n");
}

int main() {
    int T; scanf("%d", &T);
    rep(t, T) loop();
    return 0;
}