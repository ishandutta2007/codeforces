#include <bits/stdc++.h>
using namespace std;

int N, L, R, X;
int A[16], ans;

void dfs(int n, int sum, int mn, int mx)
{
    if (n > N){
        if (L <= sum && sum <= R && mx-mn >= X) ans++;
        return;
    }
    dfs(n+1, sum, mn, mx);
    dfs(n+1, sum+A[n], min(mn, A[n]), max(mx, A[n]));
}

int main()
{
    cin >> N >> L >> R >> X;
    for (int i=1;i<=N;i++) cin >> A[i];
    sort(A+1, A+N+1);
    dfs(1, 0, 2e9, 0);
    printf("%d\n", ans);
}