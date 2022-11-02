#include <stdio.h>

#define min(a,b) ((a)<(b)?(a):(b))
typedef long long lld;

lld A,B;

lld proc(lld n)
{
    int i,j,k,head,tail;
    lld re=0,v,m,mid;
    re = min(9,n);
    if (n < 10) return re;
    for (i=2;i<19;i++){
        v = 1;
        for (j=i;j--;) v *= 10;
        if (n < v) break;
        re += v/100*9;
    }
    v = 1;
    for (j=i-1;j--;) v *= 10;
    tail = n%10;
    for (m=n;m;m/=10) head = m%10;
    re += v/10*(head-1);
    mid = (n-v*head)/10;
    if (head <= tail) re += mid+1;
    else re += mid;
    return re;
}

int main()
{
    scanf("%lld%lld",&A,&B);
    printf("%lld",proc(B)-proc(A-1));
}