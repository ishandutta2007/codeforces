#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
int A[501][501], R[501];

int proc(int a[501])
{
    int ret = 0, now = 0;
    for (int i=1;i<=M;i++){
        if (a[i]) now++;
        else now = 0;
        ret = max(ret, now);
    }
    return ret;
}

int main()
{
    scanf("%d%d%d", &N, &M, &Q);
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++) scanf("%d", A[i]+j);
        R[i] = proc(A[i]);
    }
    while (Q--){
        int y, x;
        scanf("%d%d", &y, &x);
        A[y][x] ^= 1;
        R[y] = proc(A[y]);
        int ans = 0;
        for (int i=1;i<=N;i++) ans = max(ans, R[i]);
        cout << ans << endl;
    }
}