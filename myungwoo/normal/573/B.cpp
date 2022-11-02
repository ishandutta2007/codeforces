#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define pb push_back

int N;
int A[MAXN], B[MAXN];
vector <int> C[MAXN];

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        scanf("%d", A+i), B[i] = A[i];
        if (A[i] <= N) C[A[i]].pb(i);
    }
    C[0] = {0, N+1};
    for (int i=0;i<=N;i++){
        for (int t: C[i]){
            if (B[t] != i) continue;
            if (t+1 <= N && B[t+1] > i+1)
                B[t+1] = i+1, C[i+1].pb(t+1);
            if (t-1 > 0 && B[t-1] > i+1)
                B[t-1] = i+1, C[i+1].pb(t-1);
        }
//      for (int j=0;j<=N+1;j++) printf("%d ", B[j]); puts("");
    }
    int ans = 0;
    for (int i=1;i<=N;i++) ans = max(ans, B[i]);
    printf("%d\n", ans);
}