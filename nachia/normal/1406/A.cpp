#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
int A[100];
int C[101];

void loop() {
    scanf("%d", &N);
    rep(i, N) scanf("%d", &A[i]);
    rep(i, 101) C[i] = 0;
    rep(i, N) C[A[i]]++;
    int ans = 0;
    rep(i, 101) if (C[i] < 2) break; else ans++;
    rep(i, 101) if (C[i] < 1) break; else ans++;
    printf("%d\n", ans);
}

int main() {
    int T; scanf("%d", &T);
    while (T--) loop();
    return 0;
}