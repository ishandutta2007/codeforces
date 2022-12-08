#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int N; long long W[1010],H[1010],A[2020];

int main()
{
    scanf ("%d",&N);
    for (int i=0;i<N;i++){
        scanf ("%d %d",&W[i],&H[i]);
        A[i] = W[i];
        A[i+N] = H[i];
    }
    sort(A,A+2*N);
    int lim = N/2;
    long long ans = 1e18;
    for (int i=0;i<N*2;i++){
        int lie = 0; long long sum = 0;
        priority_queue<int> Q;
        for (int j=0;j<N;j++){
            if (H[j] > A[i]){
                lie++;
                sum += H[j];
                if (W[j] > A[i]) sum = 1e8;
            }
            else{
                sum += W[j];
                if (A[i] >= W[j] && W[j] > H[j]){
                    Q.push(W[j]-H[j]);
                }
            }
        }
        if (lie > lim) continue;
        while (!Q.empty() && lie < lim){
            sum -= Q.top(); Q.pop();
            lie++;
        }
        if (ans > sum * A[i])
            ans = sum * A[i];
    }

    printf ("%lld\n",ans);

    return 0;
}