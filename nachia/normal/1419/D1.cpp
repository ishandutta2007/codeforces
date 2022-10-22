#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
int A[100000];
int B[100000];

int main() {
    scanf("%d", &N);
    rep(i, N) scanf("%d", &A[i]);
    sort(A, A + N, greater<int>());
    rep(i, N) B[i] = A[i / 2 + ((N + 1) / 2) * (i % 2)];
    int ans = 0;
    for (int i = 1; i < N - 1; i++) if (B[i] < B[i - 1]) if (B[i] < B[i + 1]) ans++;
    printf("%d\n", ans);
    rep(i, N) { if (i) printf(" "); printf("%d", B[i]); } printf("\n");
    return 0;
}