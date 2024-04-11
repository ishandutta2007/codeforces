#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int N;
int A[MAXN];

void print(int s, int e)
{
    if (s == e){
        printf("%d", A[s]);
        return;
    }
    printf("(");
    print(s, e-1);
    printf("->%d)", A[e]);
}

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++) scanf("%d", A+i);
    if (A[N]){ puts("NO"); return 0; }
    if (N == 1){ puts("YES\n0"); return 0; }
    if (A[N-1]){ puts("YES"); print(1, N); return 0; }
    int p = 0;
    for (int i=N-2;i>0;i--){
        if (!A[i]){ p = i; break; }
    }
    if (!p){ puts("NO"); return 0; }
    puts("YES");
    if (p > 1){
        printf("((");
        print(1, p-1);
        printf("->(%d->", A[p]);
        print(p+1, N-1);
        printf("))->%d)\n", A[N]);
    }else{
        printf("((%d->", A[1]);
        print(2, N-1);
        printf(")->%d)\n", A[N]);
    }
}