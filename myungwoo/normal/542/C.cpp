#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

int N, F[201];
int C[201], from[201], L[201];
bool V[201];

void dfs(int n)
{
    if (C[n] || L[n]) return;
    V[n] = 1;
    if (V[F[n]]){
        int size = 1;
        for (int i=n;i!=F[n];i=from[i]) size++;
        for (int i=n;i!=F[n];i=from[i]) C[i] = size;
        C[F[n]] = size;
    }else{
        from[F[n]] = n; dfs(F[n]);
        if (!C[n]) L[n] = L[F[n]]+1;
    }
    V[n] = 0;
}

lld gcd(lld a, lld b){ return b ? gcd(b, a%b) : a; }

int main()
{
    cin >> N;
    for (int i=1;i<=N;i++) cin >> F[i];
    for (int i=1;i<=N;i++) dfs(i);
    lld ans = 1;
    for (int i=1;i<=N;i++) if (C[i]){
        lld g = gcd(ans, C[i]);
        ans = ans * C[i] / g; 
    }
    lld tmp = ans;
    for (int i=1;i<=N;i++) while (ans < L[i]) ans += tmp;
    printf("%lld\n", ans);
}