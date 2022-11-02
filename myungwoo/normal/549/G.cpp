#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int N, B[MAXN];

struct Z{
    int v, x;
} A[MAXN];

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        scanf("%d", &A[i].v);
        A[i].x = i;
    }
    sort(A+1, A+N+1, [](const Z &a, const Z &b){
        return a.v - (N - a.x) < b.v - (N - b.x);
    });
    for (int i=1;i<=N;i++) B[i] = (N - i) + A[i].v - (N - A[i].x);
    for (int i=1;i<N;i++)
        if (B[i] > B[i+1]){
            puts(":(");
            return 0;
        }
    for (int i=1;i<=N;i++) printf("%d ", B[i]); puts("");
}