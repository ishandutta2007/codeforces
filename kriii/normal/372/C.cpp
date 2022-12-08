#include <stdio.h>
#include <algorithm>

int N,M,D,I[159999],head,tail; long long V[159999],W[159999];
long long A[303],B[303],T[303];

int main()
{
    int i,p,q; long long l,f;

    scanf ("%d %d %d",&N,&M,&D);
    for (i=1;i<=M;i++){
        scanf ("%lld %lld %lld",&A[i],&B[i],&T[i]);
    }

    l = 1;
    for (i=1;i<=M;i++){
        head = tail = -1;
        p = q = 1;
        while (p <= N){
            f = p + D * (T[i] - l);
            while (q <= N && f >= q){
                while (tail < head){
                    if (V[head] < W[q]) head--;
                    else break;
                }
                ++head; I[head] = q; V[head] = W[q]; q++;
            }

            f = p - D * (T[i] - l);
            while (tail < head){
                if (I[tail+1] < f) tail++;
                else break;
            }
            W[p] = V[tail+1] + B[i] - std::abs(A[i] - p); p++;
        }

        l = T[i];
    }

    long long ans = W[1];
    for (i=2;i<=N;i++) if (ans < W[i]) ans = W[i];
    printf ("%lld",ans);

    return 0;
}