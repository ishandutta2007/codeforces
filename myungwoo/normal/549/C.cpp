#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int N, K;
int A[MAXN];

int main()
{
    scanf("%d%d", &N, &K);
    for (int i=1;i<=N;i++) scanf("%d", A+i), A[i] &= 1;
    if (N == K){
        int sum = 0;
        for (int i=1;i<=N;i++) sum ^= A[i];
        puts(sum ? "Stannis" : "Daenerys");
        return 0;
    }
    int odds = 0, evens = 0;
    for (int i=1;i<=N;i++)
        if (A[i]) odds++;
        else evens++;
    if (min(odds, evens) > (N-K)/2)
        puts((N-K)&1 ? "Stannis" : "Daenerys");
    else if (odds <= (N-K)/2)
        puts("Daenerys");
    else puts(K&1 ? "Stannis" : "Daenerys");
}