#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

void loop() {
    int N, X; scanf("%d%d", &N, &X);
    int A[1000]; rep(i, N) scanf("%d", &A[i]);
    int c = 0; rep(i, N) if (A[i] == X) c++;
    int S = 0; rep(i, N) S += A[i];
    if (c == N) { printf("0\n"); return; }
    if (c == 0) {
        if (S == X * N) printf("1\n");
        else printf("2\n");
        return;
    }
    if (c >= 2) { printf("1\n"); return; }
    printf("1\n");
}

int main() {
    int T; scanf("%d", &T);
    while (T--) loop();
    return 0;
}