#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int N, X;
int A[MAXN], dst[MAXN], code[MAXN];
int C[MAXN], S[MAXN];

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        scanf("%d", A+i);
        queue <int> que;
        que.push(A[i]); dst[A[i]] = 0; code[A[i]] = ++X;
        while (!que.empty()){
            int q = que.front(); que.pop();
            int d = dst[q];
            C[q]++; S[q] += d;
            if (q > 0){
                if (code[q>>1] != X) code[q>>1] = X, dst[q>>1] = d + 1, que.push(q >> 1);
            }
            if ((q << 1) < MAXN){
                if (code[q<<1] != X) code[q<<1] = X, dst[q<<1] = d + 1, que.push(q << 1);
            }
        }
    }
    int ans = 2e9;
    for (int i=1;i<MAXN;i++) if (C[i] == N){
        ans = min(ans, S[i]);
    }
    printf("%d\n", ans);
}