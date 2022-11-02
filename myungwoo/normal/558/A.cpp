#include <bits/stdc++.h>
using namespace std;

int N;

struct Z{
    int p, c;
} A[101];

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++) scanf("%d%d", &A[i].p, &A[i].c);
    int a = 0, b = 0;
    for (int i=1;i<=N;i++) if (A[i].p < 0) a++; else b++;
    if (a < b) for (int i=1;i<=N;i++) A[i].p *= -1;
    int ans = 0; int sign = -1;
    vector <int> V(N+1, 0);
    for (;;sign*=-1){
        int mn = 2e9, t = 0;
        for (int i=1;i<=N;i++) if (!V[i]){
            int v = sign * A[i].p;
            if (v < 0) continue;
            if (mn > v)
                mn = v, t = i;
        }
        if (!t) break;
        V[t] = 1;
        ans += A[t].c;
    }
    printf("%d\n", ans);
}